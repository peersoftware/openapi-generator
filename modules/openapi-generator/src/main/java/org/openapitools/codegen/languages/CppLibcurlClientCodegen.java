package org.openapitools.codegen.languages;

import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.Multimap;
import io.swagger.v3.oas.models.Operation;
import io.swagger.v3.oas.models.media.ArraySchema;
import io.swagger.v3.oas.models.media.Schema;
import io.swagger.v3.oas.models.responses.ApiResponse;
import io.swagger.v3.oas.models.servers.Server;
import org.openapitools.codegen.*;
import org.openapitools.codegen.meta.features.*;
import org.openapitools.codegen.model.ModelMap;
import org.openapitools.codegen.model.ModelsMap;
import org.openapitools.codegen.model.OperationMap;
import org.openapitools.codegen.model.OperationsMap;
import org.openapitools.codegen.utils.ModelUtils;

import java.math.BigDecimal;
import java.io.File;
import java.util.*;

import org.apache.commons.lang3.StringUtils;
import static com.google.common.base.Strings.isNullOrEmpty;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class CppLibcurlClientCodegen extends AbstractCppCodegen {
    static final Logger LOGGER = LoggerFactory.getLogger(CppLibcurlClientCodegen.class);
    public static final String DECLSPEC = "declspec";
    public static final String DEFAULT_INCLUDE = "defaultInclude";
    public static final String DEFAULT_PACKAGE_NAME = "CppLibcurlOpenAPIClient";
    public static final String CMAKE_MIN = "cmakeMin";

    protected String packageName = "";
    protected String packageVersion = "1.0.0";
    protected String declspec = "";
    protected String defaultInclude = "";
    protected String apiDirName = "api";
    protected String modelDirName = "model";
    protected String cmakeMin = "3.1";

    private final Set<String> parentModels = new HashSet<>();
    private final Multimap<String, CodegenModel> childrenByParent = ArrayListMultimap.create();

    public CodegenType getTag() {
        return CodegenType.CLIENT;
    }

    public String getName() {
        return "cpp-libcurl";
    }

    public String getHelp() {
        return "Generates a cpp-libcurl client.";
    }

    public CppLibcurlClientCodegen() {
        super();

        modifyFeatureSet(features -> features
                .includeDocumentationFeatures(DocumentationFeature.Readme)
                .securityFeatures(EnumSet.of(
                        SecurityFeature.BasicAuth,
                        SecurityFeature.OAuth2_Implicit,
                        SecurityFeature.ApiKey
                ))
                .excludeGlobalFeatures(
                        GlobalFeature.XMLStructureDefinitions,
                        GlobalFeature.Callbacks,
                        GlobalFeature.LinkObjects,
                        GlobalFeature.ParameterStyling,
                        GlobalFeature.MultiServer
                )
                .includeSchemaSupportFeatures(
                        SchemaSupportFeature.Polymorphism
                )
                .excludeParameterFeatures(
                        ParameterFeature.Cookie
                )
        );

        embeddedTemplateDir = templateDir = "cpp-libcurl";
        apiPackage = "org.openapitools.client.api";
        modelPackage = "org.openapitools.client.model";

        modelTemplateFiles.put("model-header.mustache", ".h");
        modelTemplateFiles.put("model-source.mustache", ".cpp");

        apiTemplateFiles.put("api-header.mustache", ".h");
        apiTemplateFiles.put("api-source.mustache", ".cpp");

        setReservedWordsLowerCase(
            Arrays.asList("ApiResponse")
        );

        cliOptions.clear();

        // CLI options
        addOption(CodegenConstants.PACKAGE_NAME, "C++ package (library) name.", DEFAULT_PACKAGE_NAME);
        addOption(CodegenConstants.MODEL_PACKAGE, "C++ namespace for models (convention: name.space.model).",
                this.modelPackage);
        addOption(CodegenConstants.API_PACKAGE, "C++ namespace for apis (convention: name.space.api).",
                this.apiPackage);
        addOption(CodegenConstants.PACKAGE_VERSION, "C++ package version.", this.packageVersion);
        addOption(DECLSPEC, "C++ preprocessor to place before the class name for handling dllexport/dllimport.",
                this.declspec);
        addOption(DEFAULT_INCLUDE,
                "The default include statement that should be placed in all headers for including things like the declspec (convention: #include \"Commons.h\" ",
                this.defaultInclude);
        addOption(CMAKE_MIN, "CMake minimum version", this.cmakeMin);

        languageSpecificPrimitives = new HashSet<>(
                Arrays.asList("int", "char", "bool", "long", "float", "double", "int32_t", "int64_t"));

        typeMapping = new HashMap<>();
        typeMapping.put("array", "std::vector");
        typeMapping.put("set", "std::vector");
        typeMapping.put("map", "std::map");
        typeMapping.put("boolean", "bool");
        typeMapping.put("string", "std::string");
        typeMapping.put("int", "int32_t");
        typeMapping.put("float", "float");
        typeMapping.put("double", "double");
        typeMapping.put("number", "double");
        typeMapping.put("date", "std::string");
        typeMapping.put("DateTime", "std::string");
        typeMapping.put("long", "int64_t");
        typeMapping.put("integer", "int32_t");
        typeMapping.put("ByteArray", "std::string");
        typeMapping.put("binary", "std::string");
        typeMapping.put("file", "std::string");
        typeMapping.put("UUID", "std::string");
        typeMapping.put("URI", "std::string");

        super.importMapping = new HashMap<>();
        importMapping.put("std::vector", "#include <vector>");
        importMapping.put("std::map", "#include <map>");
        importMapping.put("std::string", "#include <string>");
        importMapping.put("int32_t", "#include <cstdint>");
        importMapping.put("uint32_t", "#include <cstdint>");
        importMapping.put("int64_t", "#include <cstdint>");
        importMapping.put("uint64_t", "#include <cstdint>");
    }

    @Override
    public void processOpts() {
        super.processOpts();

        packageName = (String) additionalProperties.getOrDefault(CodegenConstants.PACKAGE_NAME, DEFAULT_PACKAGE_NAME);

        if (additionalProperties.containsKey(DECLSPEC)) {
            declspec = additionalProperties.get(DECLSPEC).toString();
        }

        if (additionalProperties.containsKey(DEFAULT_INCLUDE)) {
            defaultInclude = additionalProperties.get(DEFAULT_INCLUDE).toString();
        }

        if (additionalProperties.containsKey(CMAKE_MIN)) {
            cmakeMin = additionalProperties.get(CMAKE_MIN).toString();
        }

        additionalProperties.put(CodegenConstants.PACKAGE_NAME, packageName);
        additionalProperties.put("modelNamespaceDeclarations", modelPackage.replaceAll("\\.", "::"));
        additionalProperties.put("modelNamespace", modelPackage.replaceAll("\\.", "::"));
        additionalProperties.put("modelHeaderGuardPrefix", modelPackage.replaceAll("\\.", "_").toUpperCase(Locale.ROOT));
        additionalProperties.put("apiNamespaceDeclarations", apiPackage.replaceAll("\\.", "::"));
        additionalProperties.put("apiNamespace", apiPackage.replaceAll("\\.", "::"));
        additionalProperties.put("apiHeaderGuardPrefix", apiPackage.replaceAll("\\.", "_").toUpperCase(Locale.ROOT));
        additionalProperties.put("declspec", declspec);
        additionalProperties.put("defaultInclude", defaultInclude);
        additionalProperties.put("cmakeMin", cmakeMin);

        supportingFiles.add(new SupportingFile("apiclient-header.mustache", getHeaderFolder(), "ApiClient.h"));
        supportingFiles.add(new SupportingFile("apiclient-source.mustache", getSourceFolder(), "ApiClient.cpp"));
        supportingFiles.add(new SupportingFile("apiconfiguration-header.mustache", getHeaderFolder(), "ApiConfiguration.h"));
        supportingFiles.add(new SupportingFile("apiconfiguration-source.mustache", getSourceFolder(), "ApiConfiguration.cpp"));
        supportingFiles.add(new SupportingFile("apiresponse-header.mustache", getHeaderFolder(), "ApiResponse.h"));
        supportingFiles.add(new SupportingFile("apiresponse-source.mustache", getSourceFolder(), "ApiResponse.cpp"));
        supportingFiles.add(new SupportingFile("cmake-config.mustache", "", "Config.cmake.in"));
        supportingFiles.add(new SupportingFile("cmake-lists.mustache", "", "CMakeLists.txt"));
        supportingFiles.add(new SupportingFile("modelbase-header.mustache", getHeaderFolder(), "ModelBase.h"));
        supportingFiles.add(new SupportingFile("modelbase-source.mustache", getSourceFolder(), "ModelBase.cpp"));
        supportingFiles.add(new SupportingFile("utility-header.mustache", getHeaderFolder(), "Utility.h"));
        supportingFiles.add(new SupportingFile("utility-source.mustache", getSourceFolder(), "Utility.cpp"));
        supportingFiles.add(new SupportingFile("README.mustache", "", "README.md"));
    }

    protected String getHeaderFolder() {
        return "include" + File.separator + packageName;
    }

    protected String getSourceFolder() {
        return "src";
    }

    @Override
    public String apiFilename(String templateName, String tag) {
        String suffix = apiTemplateFiles().get(templateName);
        String targetOutDir = suffix.equals(".h") ? getHeaderFolder() : getSourceFolder();
        return outputFolder + File.separator + targetOutDir + File.separator + apiDirName + File.separator + toApiFilename(tag) + suffix;
    }

    @Override
    public String modelFilename(String templateName, String modelName) {
        String suffix = modelTemplateFiles().get(templateName);
        String targetOutDir = suffix.equals(".h") ? getHeaderFolder() : getSourceFolder();
        return outputFolder + File.separator + targetOutDir + File.separator + modelDirName + File.separator + toModelFilename(modelName) + suffix;
    }

    @Override
    public String toModelImport(String name) {
        if (importMapping.containsKey(name)) {
            return importMapping.get(name);
        } else {
            return "#include \"" + packageName + "/" + modelDirName + "/" + toModelFilename(name) + ".h\"";
        }
    }

    @Override
    public CodegenModel fromModel(String name, Schema model) {
        CodegenModel codegenModel = super.fromModel(name, model);

        Set<String> oldImports = codegenModel.imports;
        codegenModel.imports = new HashSet<>();
        for (String imp : oldImports) {
            String newImp = toModelImport(imp);
            if (!newImp.isEmpty()) {
                codegenModel.imports.add(newImp);
            }
        }

        return codegenModel;
    }

    @Override
    protected void handleMethodResponse(Operation operation,
                                        Map<String, Schema> schemas,
                                        CodegenOperation op,
                                        ApiResponse methodResponse,
                                        Map<String, String> schemaMappings) {
        super.handleMethodResponse(operation, schemas, op, methodResponse, schemaMappings);

        Schema response = ModelUtils.getSchemaFromResponse(methodResponse);

        response = unaliasSchema(response);
        if (response != null) {
            CodegenProperty cm = fromProperty("response", response, false);
            op.vendorExtensions.put("x-codegen-response", cm);
        }
    }

    @Override
    public void postProcessModelProperty(CodegenModel model, CodegenProperty property) {
        if (!isNullOrEmpty(model.parent)) {
            parentModels.add(model.parent);
            if (!childrenByParent.containsEntry(model.parent, model)) {
                childrenByParent.put(model.parent, model);
            }
        }
    }

    // override with any special post-processing
    @Override
    public OperationsMap postProcessOperationsWithModels(OperationsMap objs, List<ModelMap> allModels) {
        OperationMap operations = objs.getOperations();
        List<CodegenOperation> operationList = operations.getOperation();
        for (CodegenOperation op : operationList) {
            for (String hdr : op.imports) {
                if (importMapping.containsKey(hdr)) {
                    continue;
                }
                operations.put("hasModelImport", true);
                break;
            }
        }
        return objs;
    }

    @Override
    public String toModelName(String type) {
        String name = super.toModelName(type);

        if (isReservedWord(name)) {
            return escapeReservedWord(name);
        }

        return name;
    }

    @Override
    public String toModelFilename(String name) {
        return toModelName(name);
    }

    @Override
    public String toApiFilename(String name) {
        return toApiName(name);
    }

    private Boolean isStdStringSchema(Schema schema) {
        return ModelUtils.isStringSchema(schema)
                || ModelUtils.isFileSchema(schema);
    }

    /**
     * If a type is defined as an integer with a positive minimum value, then
     * treat it as an unsigned integer.
     */
    private Boolean isUnsignedInteger(Schema schema) {
        if (!ModelUtils.isIntegerSchema(schema)) {
            return false;
        }

        BigDecimal minimum = schema.getMinimum();

        return minimum != null && minimum.abs().equals(minimum);
    }

    /**
     * Optional - type declaration. This is a String which is used by the
     * templates to instantiate your types. There is typically special handling
     * for different property types
     *
     * @return a string value used as the `dataType` field for model templates,
     * `returnType` for api templates
     */
    @Override
    public String getTypeDeclaration(Schema schema) {
        String openAPIType = getSchemaType(schema);

        /*
         * getSchemaType() will resolve references and find the right type, but these checks
         * need to check any referenced schema.
         */
        schema = unaliasSchema(schema);

        if (ModelUtils.isArraySchema(schema)) {
            ArraySchema ap = (ArraySchema) schema;
            Schema inner = ap.getItems();
            return openAPIType + "<" + getTypeDeclaration(inner) + ">";
        }
        if (ModelUtils.isMapSchema(schema)) {
            Schema inner = getAdditionalProperties(schema);
            return openAPIType + "<std::string, " + getTypeDeclaration(inner) + ", std::less<>>";
        }

        if (isUnsignedInteger(schema)) {
            if (ModelUtils.isLongSchema(schema)) {
                return "uint64_t";
            }

            return "uint32_t";
        }

        if (isStdStringSchema(schema)
                || languageSpecificPrimitives.contains(openAPIType)) {
            return toModelName(openAPIType);
        }

        return "std::shared_ptr<" + openAPIType + ">";
    }

    @Override
    public String toDefaultValue(Schema p) {
        if (isStdStringSchema(p)) {
            if (p.getDefault() != null) {
                return "\"" + p.getDefault().toString() + "\"";
            } else {
                return "\"\"";
            }
        } else if (ModelUtils.isBooleanSchema(p)) {
            if (p.getDefault() != null) {
                return p.getDefault().toString();
            } else {
                return "false";
            }
        } else if (ModelUtils.isNumberSchema(p)) {
            if (ModelUtils.isFloatSchema(p)) { // float
                if (p.getDefault() != null) {
                    return p.getDefault().toString() + "f";
                } else {
                    return "0.0f";
                }
            } else { // double
                if (p.getDefault() != null) {
                    return p.getDefault().toString();
                } else {
                    return "0.0";
                }
            }
        } else if (isUnsignedInteger(p)) {
            if (ModelUtils.isLongSchema(p)) { // long
                if (p.getDefault() != null) {
                    return p.getDefault().toString() + "UL";
                } else {
                    return "0UL";
                }
            } else { // integer
                if (p.getDefault() != null) {
                    return p.getDefault().toString() + "U";
                } else {
                    return "0U";
                }
            }
        } else if (ModelUtils.isIntegerSchema(p)) {
            if (ModelUtils.isLongSchema(p)) { // long
                if (p.getDefault() != null) {
                    return p.getDefault().toString() + "L";
                } else {
                    return "0L";
                }
            } else { // integer
                if (p.getDefault() != null) {
                    return p.getDefault().toString();
                } else {
                    return "0";
                }
            }
        } else if (ModelUtils.isMapSchema(p)) {
            String inner = getSchemaType(getAdditionalProperties(p));
            return "std::map<std::string, " + inner + ", std::less<>>()";
        } else if (ModelUtils.isArraySchema(p)) {
            ArraySchema ap = (ArraySchema) p;
            Schema inner = ap.getItems();
            String innerType = getSchemaType(inner);
            /* Check the type of any reference schema before making a shared pointer */
            inner = unaliasSchema(inner);

            if (!isStdStringSchema(inner) &&
                    !languageSpecificPrimitives.contains(innerType)) {
                innerType = "std::shared_ptr<" + innerType + ">";
            }
            return "std::vector<" + innerType + ">()";
        } else if (!StringUtils.isEmpty(p.get$ref())) {
            return "std::make_shared<" + toModelName(ModelUtils.getSimpleRef(p.get$ref())) + ">()";
        }

        return "nullptr";
    }

    private void addVendorExtensions(String dataType, Map<String, Object> vendorExtensions) {
        if (dataType.startsWith("std::")) {
           vendorExtensions.put("x-cpp-is-class", true);
        }

        if (dataType.equals("std::string")) {
           vendorExtensions.put("x-cpp-is-std-string", true);
        }
    }

    @Override
    public void postProcessParameter(CodegenParameter parameter) {
        super.postProcessParameter(parameter);

        addVendorExtensions(parameter.dataType, parameter.vendorExtensions);

        boolean isPrimitiveType = parameter.isPrimitiveType == Boolean.TRUE;
        boolean isArray = parameter.isArray == Boolean.TRUE;
        boolean isMap = parameter.isMap == Boolean.TRUE;
        boolean isString = parameter.isString == Boolean.TRUE;

        if (!isPrimitiveType && !isArray && !isMap && !isString && !parameter.dataType.startsWith("std::shared_ptr")) {
            parameter.dataType = "std::shared_ptr<" + parameter.dataType + ">";
            parameter.defaultValue = "std::make_shared<" + parameter.dataType + ">()";
        }
    }

    /**
     * Optional - OpenAPI type conversion. This is used to map OpenAPI types in
     * a `Schema` into either language specific types via `typeMapping` or
     * into complex models if there is not a mapping.
     *
     * @return a string value of the type or complex model for this property
     * @see io.swagger.v3.oas.models.media.Schema
     */
    @Override
    public String getSchemaType(Schema p) {
        String openAPIType = super.getSchemaType(p);
        String type = null;
        if (typeMapping.containsKey(openAPIType)) {
            type = typeMapping.get(openAPIType);
        } else {
            type = openAPIType;
        }

        return toModelName(type);
    }

    @Override
    public Map<String, ModelsMap> postProcessAllModels(final Map<String, ModelsMap> models) {
        final Map<String, ModelsMap> processed = super.postProcessAllModels(models);
        postProcessParentModels(models);
        return processed;
    }

    private void postProcessParentModels(final Map<String, ModelsMap> models) {
        for (final String parent : parentModels) {
            final CodegenModel parentModel = ModelUtils.getModelByName(parent, models);
            final Collection<CodegenModel> childrenModels = childrenByParent.get(parent);
            for (final CodegenModel child : childrenModels) {
                processParentPropertiesInChildModel(parentModel, child);
            }
        }
    }

    /**
     * Sets the child property's isInherited flag to true if it is an inherited property
     */
    private void processParentPropertiesInChildModel(final CodegenModel parent, final CodegenModel child) {
        final Map<String, CodegenProperty> childPropertiesByName = new HashMap<>(child.vars.size());
        if (child != null && child.vars != null && !child.vars.isEmpty()) {
            for (final CodegenProperty childSchema : child.vars) {
                childPropertiesByName.put(childSchema.name, childSchema);
            }
        }

        if (parent != null && parent.vars != null && !parent.vars.isEmpty()) {
            for (final CodegenProperty parentSchema : parent.vars) {
                final CodegenProperty duplicatedByParent = childPropertiesByName.get(parentSchema.name);
                if (duplicatedByParent != null) {
                    duplicatedByParent.isInherited = true;
                }
            }
        }
    }

    @Override
    public ModelsMap postProcessModels(ModelsMap objs) {
        objs = super.postProcessModels(objs);

        for (ModelMap mo : objs.getModels()) {
            CodegenModel cm = mo.getModel();
            for (CodegenProperty var : cm.vars) {
                addVendorExtensions(var.dataType, var.vendorExtensions);
            }
        }

        return objs;
    }
}
