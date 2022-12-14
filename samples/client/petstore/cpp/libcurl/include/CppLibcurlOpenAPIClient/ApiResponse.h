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
 * ApiResponse.h
 *
 * Response class returned by API requests.
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_ApiResponse_H_
#define ORG_OPENAPITOOLS_CLIENT_API_ApiResponse_H_



#include <string>

namespace org::openapitools::client::api {

class  ErrorResponse {
public:
    long getCode() const;
    void setCode(long code);

    const std::string &getMessage() const;
    void setMessage(std::string &&message);

    bool isError() const;

private:
    long m_code{};
    std::string m_message{};
};

class  ApiResponse {
public:
    const ErrorResponse &getError() const;
    void setError(long code, std::string &&message);

    long getHttpStatus() const;
    void setHttpStatus(long status);
    bool isHttpError() const;

    const std::string &getData() const;
    void setData(std::string &&data);

private:
    ErrorResponse m_error{};
    long m_status{};
    std::string m_data{};
};

}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_ApiResponse_H_ */
