/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#include "CppLibcurlOpenAPIClient/api/UserApi.h"

#include <functional>
#include <optional>
#include <stdexcept>
#include <unordered_set>
#include <utility>

#include "CppLibcurlOpenAPIClient/Utility.h"

namespace org::openapitools::client::api {

using namespace org::openapitools::client::model;
using org::openapitools::client::api::replaceAll;

UserApi::UserApi(const std::shared_ptr<const ApiClient> &apiClient)
    : m_ApiClient(apiClient) {
}

ApiResponse
UserApi::createUser(
    const std::shared_ptr<User>& user
) const {

    // verify the required parameter 'user' is set
    if (user == nullptr) {
        throw std::invalid_argument("Missing required parameter 'user' when calling UserApi->createUser");
    }


    std::string localVarPath = "/user";
    
    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->createUser does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/json");


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
        nlohmann::json localVarJson;

        localVarJson = ModelBase::toJson(user);
        
        localVarHttpBody = localVarJson.dump();
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->createUser does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "POST", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
ApiResponse
UserApi::createUsersWithArrayInput(
    const std::vector<std::shared_ptr<User>>& user
) const {


    std::string localVarPath = "/user/createWithArray";
    
    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->createUsersWithArrayInput does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/json");


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
        nlohmann::json localVarJson;

        {
            localVarJson = nlohmann::json::array();
            for (auto& localVarItem : user) {
                if (localVarItem.get()) {
                    localVarJson.push_back(localVarItem->toJson());
                }
                
            }
        }
                localVarHttpBody = localVarJson.dump();
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->createUsersWithArrayInput does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "POST", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
ApiResponse
UserApi::createUsersWithListInput(
    const std::vector<std::shared_ptr<User>>& user
) const {


    std::string localVarPath = "/user/createWithList";
    
    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->createUsersWithListInput does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/json");


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
        nlohmann::json localVarJson;

        {
            localVarJson = nlohmann::json::array();
            for (auto& localVarItem : user) {
                if (localVarItem.get()) {
                    localVarJson.push_back(localVarItem->toJson());
                }
                
            }
        }
                localVarHttpBody = localVarJson.dump();
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->createUsersWithListInput does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "POST", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
ApiResponse
UserApi::deleteUser(
    const std::string& username
) const {


    std::string localVarPath = "/user/{username}";
    replaceAll(localVarPath, "{username}", ApiClient::parameterToString(username));

    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->deleteUser does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->deleteUser does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "DELETE", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
std::pair<ApiResponse, std::shared_ptr<User>>
UserApi::getUserByName(
    const std::string& username
) const {


    std::string localVarPath = "/user/{username}";
    replaceAll(localVarPath, "{username}", ApiClient::parameterToString(username));

    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;
    localVarResponseHttpContentTypes.emplace("application/xml");
    localVarResponseHttpContentTypes.emplace("application/json");

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->getUserByName does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->getUserByName does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "GET", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::shared_ptr<User>());
    }

    auto localVarResult(std::make_shared<User>());

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}
std::pair<ApiResponse, std::string>
UserApi::loginUser(
    const std::string& username,
    const std::string& password
) const {


    std::string localVarPath = "/user/login";
    
    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;
    localVarResponseHttpContentTypes.emplace("application/xml");
    localVarResponseHttpContentTypes.emplace("application/json");

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "text/plain";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else if (localVarResponseHttpContentTypes.find("text/plain") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "text/plain";
    }
    else {
        throw std::invalid_argument("UserApi->loginUser does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;

    {
        localVarQueryParams["username"] = ApiClient::parameterToString(username);
    }
    {
        localVarQueryParams["password"] = ApiClient::parameterToString(password);
    }

    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->loginUser does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "GET", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::string());
    }

    std::string localVarResult("");

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }
    else if (localVarResponseHttpContentType == "text/plain") {
        localVarResult = response.getData();
    }

    return std::make_pair(response, localVarResult);
}
ApiResponse
UserApi::logoutUser(
) const {


    std::string localVarPath = "/user/logout";
    
    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->logoutUser does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->logoutUser does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "GET", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
ApiResponse
UserApi::updateUser(
    const std::string& username,
    const std::shared_ptr<User>& user
) const {

    // verify the required parameter 'user' is set
    if (user == nullptr) {
        throw std::invalid_argument("Missing required parameter 'user' when calling UserApi->updateUser");
    }


    std::string localVarPath = "/user/{username}";
    replaceAll(localVarPath, "{username}", ApiClient::parameterToString(username));

    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;

    std::string localVarResponseHttpContentType;

    // use JSON if possible
    if (localVarResponseHttpContentTypes.empty()) {
        localVarResponseHttpContentType = "application/json";
    } else if (localVarResponseHttpContentTypes.find("application/json") !=
            localVarResponseHttpContentTypes.end()) {
        localVarResponseHttpContentType = "application/json";
    }
    else {
        throw std::invalid_argument("UserApi->updateUser does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/json");


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
        nlohmann::json localVarJson;

        localVarJson = ModelBase::toJson(user);
        
        localVarHttpBody = localVarJson.dump();
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("UserApi->updateUser does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "PUT", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}

}

