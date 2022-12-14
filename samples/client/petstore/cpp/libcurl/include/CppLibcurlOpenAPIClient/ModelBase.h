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

/*
 * ModelBase.h
 *
 * This is the base class for all model classes
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_ModelBase_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_ModelBase_H_



#include <nlohmann/json.hpp>

#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace org::openapitools::client::model {

class  ModelBase {
public:
    virtual ~ModelBase() = default;

    virtual nlohmann::json toJson() const = 0;
    virtual bool fromJson(const nlohmann::json& json) = 0;

    virtual bool isSet() const;

    static nlohmann::json toJson(bool val);
    static nlohmann::json toJson(float val);
    static nlohmann::json toJson(double val);
    static nlohmann::json toJson(int32_t val);
    static nlohmann::json toJson(uint32_t val);
    static nlohmann::json toJson(int64_t val);
    static nlohmann::json toJson(uint64_t val);
    static nlohmann::json toJson(const std::string& val);
    static nlohmann::json toJson(const nlohmann::json& val);
    template<typename T>
    static nlohmann::json toJson(const std::shared_ptr<T>& val);
    template<typename T>
    static nlohmann::json toJson(const std::vector<T>& val);
    template<typename T>
    static nlohmann::json toJson(const std::map<std::string, T, std::less<>>& val);

    static bool fromJson(const nlohmann::json& val, bool &);
    static bool fromJson(const nlohmann::json& val, float &);
    static bool fromJson(const nlohmann::json& val, double &);
    static bool fromJson(const nlohmann::json& val, int32_t &);
    static bool fromJson(const nlohmann::json& val, uint32_t &);
    static bool fromJson(const nlohmann::json& val, int64_t &);
    static bool fromJson(const nlohmann::json& val, uint64_t &);
    static bool fromJson(const nlohmann::json& val, std::string &);
    static bool fromJson(const nlohmann::json& val, nlohmann::json &);
    template<typename T>
    static bool fromJson(const nlohmann::json& val, std::shared_ptr<T>&);
    template<typename T>
    static bool fromJson(const nlohmann::json& val, std::vector<T> &);
    template<typename T>
    static bool fromJson(const nlohmann::json& val, std::map<std::string, T, std::less<>> &);

private:
    bool m_IsSet{false};
};

template<typename T>
nlohmann::json ModelBase::toJson(const std::shared_ptr<T>& val) {
    if (val != nullptr) {
        return val->toJson();
    }
    return nlohmann::json();
}
template<typename T>
nlohmann::json ModelBase::toJson(const std::vector<T>& value) {
    nlohmann::json ret;

    for (const auto &x : value) {
        ret.push_back(toJson(x));
    }
    return ret;
}
template<typename T>
nlohmann::json ModelBase::toJson(const std::map<std::string, T, std::less<>>& val) {
    auto obj = nlohmann::json::object();

    for (const auto &itemkey : val) {
        obj[itemkey.first] = toJson(itemkey.second);
    }
    return obj;
}

template<typename T>
bool ModelBase::fromJson(const nlohmann::json& val, std::shared_ptr<T> &outVal) {
    bool ok = false;

    if (outVal == nullptr) {
        outVal = std::make_shared<T>();
    }
    if (outVal != nullptr) {
        ok = outVal->fromJson(val);
    }
    return ok;
}
template<typename T>
bool ModelBase::fromJson(const nlohmann::json& val, std::vector<T> &outVal) {
    bool ok = true;

    if (val.is_array()) {
        for (const auto &jitem : val) {
            T item;
            ok &= fromJson(jitem, item);
            outVal.emplace_back(std::move(item));
        }
    } else {
        ok = false;
    }
    return ok;
}
template<typename T>
bool ModelBase::fromJson(const nlohmann::json& val, std::map<std::string, T, std::less<>> &outVal) {
    bool ok = true;

    if (val.is_object()) {
        for (auto jitem = val.cbegin(); jitem != val.cend(); ++jitem) {
            T itemVal;
            ok &= fromJson(jitem.value(), itemVal);
            outVal.emplace(std::pair<std::string, T>(jitem.key(), std::move(itemVal)));
        }
    } else {
        ok = false;
    }
    return ok;
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_ModelBase_H_ */
