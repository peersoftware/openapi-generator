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


#include "CppLibcurlOpenAPIClient/api/PetApi.h"

#include <functional>
#include <optional>
#include <stdexcept>
#include <unordered_set>
#include <utility>

#include "CppLibcurlOpenAPIClient/Utility.h"

namespace org::openapitools::client::api {

using namespace org::openapitools::client::model;
using org::openapitools::client::api::replaceAll;

PetApi::PetApi(const std::shared_ptr<const ApiClient> &apiClient)
    : m_ApiClient(apiClient) {
}

std::pair<ApiResponse, std::shared_ptr<Pet>>
PetApi::addPet(
    const std::shared_ptr<Pet>& pet
) const {

    // verify the required parameter 'pet' is set
    if (pet == nullptr) {
        throw std::invalid_argument("Missing required parameter 'pet' when calling PetApi->addPet");
    }


    std::string localVarPath = "/pet";
    
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
        throw std::invalid_argument("PetApi->addPet does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/json");
    localVarConsumeHttpContentTypes.emplace("application/xml");


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
        nlohmann::json localVarJson;

        localVarJson = ModelBase::toJson(pet);
        
        localVarHttpBody = localVarJson.get<std::string>();
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("PetApi->addPet does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "POST", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::shared_ptr<Pet>());
    }

    std::shared_ptr<Pet> localVarResult(std::make_shared<Pet>());

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}
ApiResponse
PetApi::deletePet(
    int64_t petId,
    std::optional<std::string> apiKey
) const {


    std::string localVarPath = "/pet/{petId}";
    replaceAll(localVarPath, "{petId}", ApiClient::parameterToString(petId));

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
        throw std::invalid_argument("PetApi->deletePet does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;

    if (apiKey)
    {
        localVarHeaderParams["api_key"] = ApiClient::parameterToString(*apiKey);
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
        throw std::invalid_argument("PetApi->deletePet does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "DELETE", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
std::pair<ApiResponse, std::vector<std::shared_ptr<Pet>>>
PetApi::findPetsByStatus(
    const std::vector<std::string>& status
) const {


    std::string localVarPath = "/pet/findByStatus";
    
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
        throw std::invalid_argument("PetApi->findPetsByStatus does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;

    {
        localVarQueryParams["status"] = ApiClient::parameterToString(status);
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
        throw std::invalid_argument("PetApi->findPetsByStatus does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "GET", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::vector<std::shared_ptr<Pet>>());
    }

    std::vector<std::shared_ptr<Pet>> localVarResult;

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}
std::pair<ApiResponse, std::vector<std::shared_ptr<Pet>>>
PetApi::findPetsByTags(
    const std::vector<std::string>& tags
) const {


    std::string localVarPath = "/pet/findByTags";
    
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
        throw std::invalid_argument("PetApi->findPetsByTags does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;

    {
        localVarQueryParams["tags"] = ApiClient::parameterToString(tags);
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
        throw std::invalid_argument("PetApi->findPetsByTags does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "GET", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::vector<std::shared_ptr<Pet>>());
    }

    std::vector<std::shared_ptr<Pet>> localVarResult;

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}
std::pair<ApiResponse, std::shared_ptr<Pet>>
PetApi::getPetById(
    int64_t petId
) const {


    std::string localVarPath = "/pet/{petId}";
    replaceAll(localVarPath, "{petId}", ApiClient::parameterToString(petId));

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
        throw std::invalid_argument("PetApi->getPetById does not produce any supported media type");
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
        throw std::invalid_argument("PetApi->getPetById does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "GET", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::shared_ptr<Pet>());
    }

    std::shared_ptr<Pet> localVarResult(std::make_shared<Pet>());

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}
std::pair<ApiResponse, std::shared_ptr<Pet>>
PetApi::updatePet(
    const std::shared_ptr<Pet>& pet
) const {

    // verify the required parameter 'pet' is set
    if (pet == nullptr) {
        throw std::invalid_argument("Missing required parameter 'pet' when calling PetApi->updatePet");
    }


    std::string localVarPath = "/pet";
    
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
        throw std::invalid_argument("PetApi->updatePet does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/json");
    localVarConsumeHttpContentTypes.emplace("application/xml");


    std::string localVarRequestHttpContentType;
    std::string localVarHttpBody;

    // use JSON if possible
    if (localVarConsumeHttpContentTypes.empty() ||
            localVarConsumeHttpContentTypes.find("application/json") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/json";
        nlohmann::json localVarJson;

        localVarJson = ModelBase::toJson(pet);
        
        localVarHttpBody = localVarJson.get<std::string>();
    } else if (localVarConsumeHttpContentTypes.find("application/x-www-form-urlencoded") != localVarConsumeHttpContentTypes.end()) {
        localVarRequestHttpContentType = "application/x-www-form-urlencoded";
    } else {
        throw std::invalid_argument("PetApi->updatePet does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "PUT", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::shared_ptr<Pet>());
    }

    std::shared_ptr<Pet> localVarResult(std::make_shared<Pet>());

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}
ApiResponse
PetApi::updatePetWithForm(
    int64_t petId,
    std::optional<std::string> name,
    std::optional<std::string> status
) const {


    std::string localVarPath = "/pet/{petId}";
    replaceAll(localVarPath, "{petId}", ApiClient::parameterToString(petId));

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
        throw std::invalid_argument("PetApi->updatePetWithForm does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("application/x-www-form-urlencoded");

    if (name)
    {
        localVarFormParams["name"] = ApiClient::parameterToString(*name);
    }
    if (status)
    {
        localVarFormParams["status"] = ApiClient::parameterToString(*status);
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
        throw std::invalid_argument("PetApi->updatePetWithForm does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "POST", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);

    return response;
}
std::pair<ApiResponse, std::shared_ptr<r_ApiResponse>>
PetApi::uploadFile(
    int64_t petId,
    std::optional<std::string> additionalMetadata,
    std::optional<std::string> file
) const {


    std::string localVarPath = "/pet/{petId}/uploadImage";
    replaceAll(localVarPath, "{petId}", ApiClient::parameterToString(petId));

    std::map<std::string, std::string, std::less<>> localVarQueryParams;
    std::map<std::string, std::string, std::less<>> localVarHeaderParams;
    std::map<std::string, std::string, std::less<>> localVarFormParams;

    std::unordered_set<std::string> localVarResponseHttpContentTypes;
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
        throw std::invalid_argument("PetApi->uploadFile does not produce any supported media type");
    }

    localVarHeaderParams["Accept"] = localVarResponseHttpContentType;

    std::unordered_set<std::string> localVarConsumeHttpContentTypes;
    localVarConsumeHttpContentTypes.emplace("multipart/form-data");

    if (additionalMetadata)
    {
        localVarFormParams["additionalMetadata"] = ApiClient::parameterToString(*additionalMetadata);
    }
    if (file)
    {
        localVarFormParams["file"] = ApiClient::parameterToString(*file);
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
        throw std::invalid_argument("PetApi->uploadFile does not consume any supported media type");
    }

    auto response = m_ApiClient->callApi(
        localVarPath, "POST", localVarQueryParams, localVarHeaderParams,
        localVarFormParams, localVarRequestHttpContentType, localVarHttpBody);


    if (response.getError().isError() || response.isHttpError()) {
        return std::make_pair(response, std::shared_ptr<r_ApiResponse>());
    }

    std::shared_ptr<r_ApiResponse> localVarResult(std::make_shared<r_ApiResponse>());

    if (localVarResponseHttpContentType == "application/json") {
        auto localVarJson = nlohmann::json::parse(response.getData());

        ModelBase::fromJson(localVarJson, localVarResult);
    }

    return std::make_pair(response, localVarResult);
}

}

