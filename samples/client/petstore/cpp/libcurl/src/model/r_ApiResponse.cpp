/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.3.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "CppLibcurlOpenAPIClient/model/r_ApiResponse.h"

namespace org::openapitools::client::model {



nlohmann::json r_ApiResponse::toJson() const {
    nlohmann::json val = nlohmann::json::object();
    
    if (m_CodeIsSet) {
        val["code"] = ModelBase::toJson(m_Code);
    }
    if (m_TypeIsSet) {
        val["type"] = ModelBase::toJson(m_Type);
    }
    if (m_MessageIsSet) {
        val["message"] = ModelBase::toJson(m_Message);
    }

    return val;
}

bool r_ApiResponse::fromJson(const nlohmann::json& val) {
    bool ok = true;
    
    if (val.contains("code")) {
        const nlohmann::json& fieldValue = val.at("code");
        if (!fieldValue.is_null()) {
            int32_t refVal_setCode;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCode);
            setCode(refVal_setCode);
        }
    }
    if (val.contains("type")) {
        const nlohmann::json& fieldValue = val.at("type");
        if (!fieldValue.is_null()) {
            std::string refVal_setType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setType);
            setType(refVal_setType);
        }
    }
    if (val.contains("message")) {
        const nlohmann::json& fieldValue = val.at("message");
        if (!fieldValue.is_null()) {
            std::string refVal_setMessage;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMessage);
            setMessage(refVal_setMessage);
        }
    }
    return ok;
}

int32_t r_ApiResponse::getCode() const {
    return m_Code;
}

void r_ApiResponse::setCode(int32_t value) {
    m_Code = value;
    m_CodeIsSet = true;
}

bool r_ApiResponse::codeIsSet() const {
    return m_CodeIsSet;
}

void r_ApiResponse::unsetCode() {
    m_CodeIsSet = false;
}
const std::string& r_ApiResponse::getType() const {
    return m_Type;
}

void r_ApiResponse::setType(std::string_view value) {
    m_Type = value;
    m_TypeIsSet = true;
}

bool r_ApiResponse::typeIsSet() const {
    return m_TypeIsSet;
}

void r_ApiResponse::unsetType() {
    m_TypeIsSet = false;
}
const std::string& r_ApiResponse::getMessage() const {
    return m_Message;
}

void r_ApiResponse::setMessage(std::string_view value) {
    m_Message = value;
    m_MessageIsSet = true;
}

bool r_ApiResponse::messageIsSet() const {
    return m_MessageIsSet;
}

void r_ApiResponse::unsetMessage() {
    m_MessageIsSet = false;
}
}


