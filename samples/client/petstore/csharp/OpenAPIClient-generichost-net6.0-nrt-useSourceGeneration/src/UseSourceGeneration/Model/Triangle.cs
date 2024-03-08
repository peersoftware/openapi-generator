// <auto-generated>
/*
 * OpenAPI Petstore
 *
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * Generated by: https://github.com/openapitools/openapi-generator.git
 */

#nullable enable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.ComponentModel.DataAnnotations;
using OpenAPIClientUtils = UseSourceGeneration.Client.ClientUtils;
using System.Text.Json.Serialization.Metadata;
using UseSourceGeneration.Client;

namespace UseSourceGeneration.Model
{
    /// <summary>
    /// Triangle
    /// </summary>
    public partial class Triangle : IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Triangle" /> class.
        /// </summary>
        /// <param name="equilateralTriangle"></param>
        /// <param name="triangleType">triangleType</param>
        public Triangle(EquilateralTriangle equilateralTriangle, string triangleType)
        {
            EquilateralTriangle = equilateralTriangle;
            TriangleType = triangleType;
            OnCreated();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Triangle" /> class.
        /// </summary>
        /// <param name="isoscelesTriangle"></param>
        /// <param name="triangleType">triangleType</param>
        public Triangle(IsoscelesTriangle isoscelesTriangle, string triangleType)
        {
            IsoscelesTriangle = isoscelesTriangle;
            TriangleType = triangleType;
            OnCreated();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Triangle" /> class.
        /// </summary>
        /// <param name="scaleneTriangle"></param>
        /// <param name="triangleType">triangleType</param>
        public Triangle(ScaleneTriangle scaleneTriangle, string triangleType)
        {
            ScaleneTriangle = scaleneTriangle;
            TriangleType = triangleType;
            OnCreated();
        }

        partial void OnCreated();

        /// <summary>
        /// Gets or Sets EquilateralTriangle
        /// </summary>
        public EquilateralTriangle? EquilateralTriangle { get; set; }

        /// <summary>
        /// Gets or Sets IsoscelesTriangle
        /// </summary>
        public IsoscelesTriangle? IsoscelesTriangle { get; set; }

        /// <summary>
        /// Gets or Sets ScaleneTriangle
        /// </summary>
        public ScaleneTriangle? ScaleneTriangle { get; set; }

        /// <summary>
        /// Gets or Sets TriangleType
        /// </summary>
        [JsonPropertyName("triangleType")]
        public string TriangleType { get; set; }

        /// <summary>
        /// Gets or Sets additional properties
        /// </summary>
        [JsonExtensionData]
        public Dictionary<string, JsonElement> AdditionalProperties { get; } = new Dictionary<string, JsonElement>();

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("class Triangle {\n");
            sb.Append("  TriangleType: ").Append(TriangleType).Append("\n");
            sb.Append("  AdditionalProperties: ").Append(AdditionalProperties).Append("\n");
            sb.Append("}\n");
            return sb.ToString();
        }

        /// <summary>
        /// To validate all properties of the instance
        /// </summary>
        /// <param name="validationContext">Validation context</param>
        /// <returns>Validation Result</returns>
        IEnumerable<System.ComponentModel.DataAnnotations.ValidationResult> IValidatableObject.Validate(ValidationContext validationContext)
        {
            return this.BaseValidate(validationContext);
        }

        /// <summary>
        /// To validate all properties of the instance
        /// </summary>
        /// <param name="validationContext">Validation context</param>
        /// <returns>Validation Result</returns>
        protected IEnumerable<System.ComponentModel.DataAnnotations.ValidationResult> BaseValidate(ValidationContext validationContext)
        {
            yield break;
        }
    }

    /// <summary>
    /// A Json converter for type <see cref="Triangle" />
    /// </summary>
    public class TriangleJsonConverter : JsonConverter<Triangle>
    {
        /// <summary>
        /// Deserializes json to <see cref="Triangle" />
        /// </summary>
        /// <param name="utf8JsonReader"></param>
        /// <param name="typeToConvert"></param>
        /// <param name="jsonSerializerOptions"></param>
        /// <returns></returns>
        /// <exception cref="JsonException"></exception>
        public override Triangle Read(ref Utf8JsonReader utf8JsonReader, Type typeToConvert, JsonSerializerOptions jsonSerializerOptions)
        {
            int currentDepth = utf8JsonReader.CurrentDepth;

            if (utf8JsonReader.TokenType != JsonTokenType.StartObject && utf8JsonReader.TokenType != JsonTokenType.StartArray)
                throw new JsonException();

            JsonTokenType startingTokenType = utf8JsonReader.TokenType;

            Option<string?> triangleType = default;

            EquilateralTriangle? equilateralTriangle = null;
            IsoscelesTriangle? isoscelesTriangle = null;
            ScaleneTriangle? scaleneTriangle = null;

            Utf8JsonReader utf8JsonReaderDiscriminator = utf8JsonReader;
            while (utf8JsonReaderDiscriminator.Read())
            {
                if (startingTokenType == JsonTokenType.StartObject && utf8JsonReaderDiscriminator.TokenType == JsonTokenType.EndObject && currentDepth == utf8JsonReaderDiscriminator.CurrentDepth)
                    break;

                if (startingTokenType == JsonTokenType.StartArray && utf8JsonReaderDiscriminator.TokenType == JsonTokenType.EndArray && currentDepth == utf8JsonReaderDiscriminator.CurrentDepth)
                    break;

                if (utf8JsonReaderDiscriminator.TokenType == JsonTokenType.PropertyName && currentDepth == utf8JsonReaderDiscriminator.CurrentDepth - 1)
                {
                    string? localVarJsonPropertyName = utf8JsonReaderDiscriminator.GetString();
                    utf8JsonReaderDiscriminator.Read();
                    if (localVarJsonPropertyName?.Equals("triangleType") ?? false)
                    {
                        string? discriminator = utf8JsonReaderDiscriminator.GetString();
                        if (discriminator?.Equals("EquilateralTriangle") ?? false)
                        {
                            Utf8JsonReader utf8JsonReaderEquilateralTriangle = utf8JsonReader;
                            equilateralTriangle = JsonSerializer.Deserialize<EquilateralTriangle>(ref utf8JsonReaderEquilateralTriangle, jsonSerializerOptions);
                        }
                        if (discriminator?.Equals("IsoscelesTriangle") ?? false)
                        {
                            Utf8JsonReader utf8JsonReaderIsoscelesTriangle = utf8JsonReader;
                            isoscelesTriangle = JsonSerializer.Deserialize<IsoscelesTriangle>(ref utf8JsonReaderIsoscelesTriangle, jsonSerializerOptions);
                        }
                        if (discriminator?.Equals("ScaleneTriangle") ?? false)
                        {
                            Utf8JsonReader utf8JsonReaderScaleneTriangle = utf8JsonReader;
                            scaleneTriangle = JsonSerializer.Deserialize<ScaleneTriangle>(ref utf8JsonReaderScaleneTriangle, jsonSerializerOptions);
                        }
                    }
                }
            }

            while (utf8JsonReader.Read())
            {
                if (startingTokenType == JsonTokenType.StartObject && utf8JsonReader.TokenType == JsonTokenType.EndObject && currentDepth == utf8JsonReader.CurrentDepth)
                    break;

                if (startingTokenType == JsonTokenType.StartArray && utf8JsonReader.TokenType == JsonTokenType.EndArray && currentDepth == utf8JsonReader.CurrentDepth)
                    break;

                if (utf8JsonReader.TokenType == JsonTokenType.PropertyName && currentDepth == utf8JsonReader.CurrentDepth - 1)
                {
                    string? localVarJsonPropertyName = utf8JsonReader.GetString();
                    utf8JsonReader.Read();

                    switch (localVarJsonPropertyName)
                    {
                        case "triangleType":
                            triangleType = new Option<string?>(utf8JsonReader.GetString()!);
                            break;
                        default:
                            break;
                    }
                }
            }

            if (!triangleType.IsSet)
                throw new ArgumentException("Property is required for class Triangle.", nameof(triangleType));

            if (triangleType.IsSet && triangleType.Value == null)
                throw new ArgumentNullException(nameof(triangleType), "Property is not nullable for class Triangle.");

            if (equilateralTriangle != null)
                return new Triangle(equilateralTriangle, triangleType.Value!);

            if (isoscelesTriangle != null)
                return new Triangle(isoscelesTriangle, triangleType.Value!);

            if (scaleneTriangle != null)
                return new Triangle(scaleneTriangle, triangleType.Value!);

            throw new JsonException();
        }

        /// <summary>
        /// Serializes a <see cref="Triangle" />
        /// </summary>
        /// <param name="writer"></param>
        /// <param name="triangle"></param>
        /// <param name="jsonSerializerOptions"></param>
        /// <exception cref="NotImplementedException"></exception>
        public override void Write(Utf8JsonWriter writer, Triangle triangle, JsonSerializerOptions jsonSerializerOptions)
        {
            writer.WriteStartObject();

            if (triangle.EquilateralTriangle != null) {
                EquilateralTriangleJsonConverter equilateralTriangleJsonConverter = (EquilateralTriangleJsonConverter) jsonSerializerOptions.Converters.First(c => c.CanConvert(triangle.EquilateralTriangle.GetType()));
                equilateralTriangleJsonConverter.WriteProperties(ref writer, triangle.EquilateralTriangle, jsonSerializerOptions);
            }

            if (triangle.IsoscelesTriangle != null) {
                IsoscelesTriangleJsonConverter isoscelesTriangleJsonConverter = (IsoscelesTriangleJsonConverter) jsonSerializerOptions.Converters.First(c => c.CanConvert(triangle.IsoscelesTriangle.GetType()));
                isoscelesTriangleJsonConverter.WriteProperties(ref writer, triangle.IsoscelesTriangle, jsonSerializerOptions);
            }

            if (triangle.ScaleneTriangle != null) {
                ScaleneTriangleJsonConverter scaleneTriangleJsonConverter = (ScaleneTriangleJsonConverter) jsonSerializerOptions.Converters.First(c => c.CanConvert(triangle.ScaleneTriangle.GetType()));
                scaleneTriangleJsonConverter.WriteProperties(ref writer, triangle.ScaleneTriangle, jsonSerializerOptions);
            }

            WriteProperties(ref writer, triangle, jsonSerializerOptions);
            writer.WriteEndObject();
        }

        /// <summary>
        /// Serializes the properties of <see cref="Triangle" />
        /// </summary>
        /// <param name="writer"></param>
        /// <param name="triangle"></param>
        /// <param name="jsonSerializerOptions"></param>
        /// <exception cref="NotImplementedException"></exception>
        public void WriteProperties(ref Utf8JsonWriter writer, Triangle triangle, JsonSerializerOptions jsonSerializerOptions)
        {
            if (triangle.TriangleType == null)
                throw new ArgumentNullException(nameof(triangle.TriangleType), "Property is required for class Triangle.");

            writer.WriteString("triangleType", triangle.TriangleType);
        }
    }

    /// <summary>
    /// The TriangleSerializationContext
    /// </summary>
    [JsonSourceGenerationOptions(WriteIndented = true, GenerationMode = JsonSourceGenerationMode.Metadata | JsonSourceGenerationMode.Serialization)]
    [JsonSerializable(typeof(Triangle))]
    public partial class TriangleSerializationContext : JsonSerializerContext { }
}
