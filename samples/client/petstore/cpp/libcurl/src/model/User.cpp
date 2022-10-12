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



#include "CppLibcurlOpenAPIClient/model/User.h"

namespace org::openapitools::client::model {



nlohmann::json User::toJson() const {
    nlohmann::json val = nlohmann::json::object();
    
    if (m_IdIsSet) {
        val["id"] = ModelBase::toJson(m_Id);
    }
    if (m_UsernameIsSet) {
        val["username"] = ModelBase::toJson(m_Username);
    }
    if (m_FirstNameIsSet) {
        val["firstName"] = ModelBase::toJson(m_FirstName);
    }
    if (m_LastNameIsSet) {
        val["lastName"] = ModelBase::toJson(m_LastName);
    }
    if (m_EmailIsSet) {
        val["email"] = ModelBase::toJson(m_Email);
    }
    if (m_PasswordIsSet) {
        val["password"] = ModelBase::toJson(m_Password);
    }
    if (m_PhoneIsSet) {
        val["phone"] = ModelBase::toJson(m_Phone);
    }
    if (m_UserStatusIsSet) {
        val["userStatus"] = ModelBase::toJson(m_UserStatus);
    }

    return val;
}

bool User::fromJson(const nlohmann::json& val) {
    bool ok = true;
    
    if (val.contains("id")) {
        const nlohmann::json& fieldValue = val.at("id");
        if (!fieldValue.is_null()) {
            int64_t refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
        }
    }
    if (val.contains("username")) {
        const nlohmann::json& fieldValue = val.at("username");
        if (!fieldValue.is_null()) {
            std::string refVal_setUsername;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUsername);
            setUsername(refVal_setUsername);
        }
    }
    if (val.contains("firstName")) {
        const nlohmann::json& fieldValue = val.at("firstName");
        if (!fieldValue.is_null()) {
            std::string refVal_setFirstName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFirstName);
            setFirstName(refVal_setFirstName);
        }
    }
    if (val.contains("lastName")) {
        const nlohmann::json& fieldValue = val.at("lastName");
        if (!fieldValue.is_null()) {
            std::string refVal_setLastName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLastName);
            setLastName(refVal_setLastName);
        }
    }
    if (val.contains("email")) {
        const nlohmann::json& fieldValue = val.at("email");
        if (!fieldValue.is_null()) {
            std::string refVal_setEmail;
            ok &= ModelBase::fromJson(fieldValue, refVal_setEmail);
            setEmail(refVal_setEmail);
        }
    }
    if (val.contains("password")) {
        const nlohmann::json& fieldValue = val.at("password");
        if (!fieldValue.is_null()) {
            std::string refVal_setPassword;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPassword);
            setPassword(refVal_setPassword);
        }
    }
    if (val.contains("phone")) {
        const nlohmann::json& fieldValue = val.at("phone");
        if (!fieldValue.is_null()) {
            std::string refVal_setPhone;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPhone);
            setPhone(refVal_setPhone);
        }
    }
    if (val.contains("userStatus")) {
        const nlohmann::json& fieldValue = val.at("userStatus");
        if (!fieldValue.is_null()) {
            int32_t refVal_setUserStatus;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUserStatus);
            setUserStatus(refVal_setUserStatus);
        }
    }
    return ok;
}

int64_t User::getId() const {
    return m_Id;
}

void User::setId(int64_t value) {
    m_Id = value;
    m_IdIsSet = true;
}

bool User::idIsSet() const {
    return m_IdIsSet;
}

void User::unsetId() {
    m_IdIsSet = false;
}
const std::string& User::getUsername() const {
    return m_Username;
}

void User::setUsername(std::string_view value) {
    m_Username = value;
    m_UsernameIsSet = true;
}

bool User::usernameIsSet() const {
    return m_UsernameIsSet;
}

void User::unsetUsername() {
    m_UsernameIsSet = false;
}
const std::string& User::getFirstName() const {
    return m_FirstName;
}

void User::setFirstName(std::string_view value) {
    m_FirstName = value;
    m_FirstNameIsSet = true;
}

bool User::firstNameIsSet() const {
    return m_FirstNameIsSet;
}

void User::unsetFirstName() {
    m_FirstNameIsSet = false;
}
const std::string& User::getLastName() const {
    return m_LastName;
}

void User::setLastName(std::string_view value) {
    m_LastName = value;
    m_LastNameIsSet = true;
}

bool User::lastNameIsSet() const {
    return m_LastNameIsSet;
}

void User::unsetLastName() {
    m_LastNameIsSet = false;
}
const std::string& User::getEmail() const {
    return m_Email;
}

void User::setEmail(std::string_view value) {
    m_Email = value;
    m_EmailIsSet = true;
}

bool User::emailIsSet() const {
    return m_EmailIsSet;
}

void User::unsetEmail() {
    m_EmailIsSet = false;
}
const std::string& User::getPassword() const {
    return m_Password;
}

void User::setPassword(std::string_view value) {
    m_Password = value;
    m_PasswordIsSet = true;
}

bool User::passwordIsSet() const {
    return m_PasswordIsSet;
}

void User::unsetPassword() {
    m_PasswordIsSet = false;
}
const std::string& User::getPhone() const {
    return m_Phone;
}

void User::setPhone(std::string_view value) {
    m_Phone = value;
    m_PhoneIsSet = true;
}

bool User::phoneIsSet() const {
    return m_PhoneIsSet;
}

void User::unsetPhone() {
    m_PhoneIsSet = false;
}
int32_t User::getUserStatus() const {
    return m_UserStatus;
}

void User::setUserStatus(int32_t value) {
    m_UserStatus = value;
    m_UserStatusIsSet = true;
}

bool User::userStatusIsSet() const {
    return m_UserStatusIsSet;
}

void User::unsetUserStatus() {
    m_UserStatusIsSet = false;
}
}


