/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.2.1-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * Tag.h
 *
 * A tag for a pet
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_Tag_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_Tag_H_


#include <nlohmann/json.hpp>

#include "CppLibcurlOpenAPIClient/ModelBase.h"

#include <string>

namespace org::openapitools::client::model {


/// <summary>
/// A tag for a pet
/// </summary>
class  Tag
    : public ModelBase {
public:
    /////////////////////////////////////////////
    /// ModelBase overrides
    nlohmann::json toJson() const override;
    bool fromJson(const nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// Tag members

    /// <summary>
    /// 
    /// </summary>
    int64_t getId() const;
    bool idIsSet() const;
    void unsetId();

    void setId(int64_t value);

    /// <summary>
    /// 
    /// </summary>
    const std::string& getName() const;
    bool nameIsSet() const;
    void unsetName();

    void setName(std::string_view value);


private:
    int64_t m_Id{ 0L };
    bool m_IdIsSet{false};
    std::string m_Name{ "" };
    bool m_NameIsSet{false};
};


}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_Tag_H_ */
