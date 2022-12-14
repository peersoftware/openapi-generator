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
 * StoreApi.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_StoreApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_StoreApi_H_


#include <memory>
#include <optional>
#include <utility>

#include "CppLibcurlOpenAPIClient/ApiClient.h"
#include "CppLibcurlOpenAPIClient/ApiResponse.h"

#include "CppLibcurlOpenAPIClient/model/Order.h"
#include <map>
#include <string>

namespace org::openapitools::client::api {

using namespace org::openapitools::client::model;

class  StoreApi {
public:
    explicit StoreApi(const std::shared_ptr<const ApiClient> &apiClient);

    /// <summary>
    /// Delete purchase order by ID
    /// </summary>
    /// <remarks>
    /// For valid response try integer IDs with value < 1000. Anything above 1000 or nonintegers will generate API errors
    /// </remarks>
    /// <param name="orderId">ID of the order that needs to be deleted</param>
    ApiResponse deleteOrder(
        const std::string& orderId
    ) const;
    /// <summary>
    /// Returns pet inventories by status
    /// </summary>
    /// <remarks>
    /// Returns a map of status codes to quantities
    /// </remarks>
    std::pair<ApiResponse, std::map<std::string, int32_t, std::less<>>> getInventory(
    ) const;
    /// <summary>
    /// Find purchase order by ID
    /// </summary>
    /// <remarks>
    /// For valid response try integer IDs with value <= 5 or > 10. Other values will generate exceptions
    /// </remarks>
    /// <param name="orderId">ID of pet that needs to be fetched</param>
    std::pair<ApiResponse, std::shared_ptr<Order>> getOrderById(
        uint64_t orderId
    ) const;
    /// <summary>
    /// Place an order for a pet
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="order">order placed for purchasing the pet</param>
    std::pair<ApiResponse, std::shared_ptr<Order>> placeOrder(
        const std::shared_ptr<Order>& order
    ) const;

private:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_StoreApi_H_ */

