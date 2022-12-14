/*
OpenAPI Petstore

This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\

API version: 1.0.0
*/

// Code generated by OpenAPI Generator (https://openapi-generator.tech); DO NOT EDIT.

package petstore

import (
	"encoding/json"
)

// checks if the AdditionalPropertiesAnyType type satisfies the MappedNullable interface at compile time
var _ MappedNullable = &AdditionalPropertiesAnyType{}

// AdditionalPropertiesAnyType struct for AdditionalPropertiesAnyType
type AdditionalPropertiesAnyType struct {
	Name *string `json:"name,omitempty"`
}

// NewAdditionalPropertiesAnyType instantiates a new AdditionalPropertiesAnyType object
// This constructor will assign default values to properties that have it defined,
// and makes sure properties required by API are set, but the set of arguments
// will change when the set of required properties is changed
func NewAdditionalPropertiesAnyType() *AdditionalPropertiesAnyType {
	this := AdditionalPropertiesAnyType{}
	return &this
}

// NewAdditionalPropertiesAnyTypeWithDefaults instantiates a new AdditionalPropertiesAnyType object
// This constructor will only assign default values to properties that have it defined,
// but it doesn't guarantee that properties required by API are set
func NewAdditionalPropertiesAnyTypeWithDefaults() *AdditionalPropertiesAnyType {
	this := AdditionalPropertiesAnyType{}
	return &this
}

// GetName returns the Name field value if set, zero value otherwise.
func (o *AdditionalPropertiesAnyType) GetName() string {
	if o == nil || isNil(o.Name) {
		var ret string
		return ret
	}
	return *o.Name
}

// GetNameOk returns a tuple with the Name field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *AdditionalPropertiesAnyType) GetNameOk() (*string, bool) {
	if o == nil || isNil(o.Name) {
		return nil, false
	}
	return o.Name, true
}

// HasName returns a boolean if a field has been set.
func (o *AdditionalPropertiesAnyType) HasName() bool {
	if o != nil && !isNil(o.Name) {
		return true
	}

	return false
}

// SetName gets a reference to the given string and assigns it to the Name field.
func (o *AdditionalPropertiesAnyType) SetName(v string) {
	o.Name = &v
}

func (o AdditionalPropertiesAnyType) MarshalJSON() ([]byte, error) {
	toSerialize,err := o.ToMap()
	if err != nil {
		return []byte{}, err
	}
	return json.Marshal(toSerialize)
}

func (o AdditionalPropertiesAnyType) ToMap() (map[string]interface{}, error) {
	toSerialize := map[string]interface{}{}
	if !isNil(o.Name) {
		toSerialize["name"] = o.Name
	}
	return toSerialize, nil
}

type NullableAdditionalPropertiesAnyType struct {
	value *AdditionalPropertiesAnyType
	isSet bool
}

func (v NullableAdditionalPropertiesAnyType) Get() *AdditionalPropertiesAnyType {
	return v.value
}

func (v *NullableAdditionalPropertiesAnyType) Set(val *AdditionalPropertiesAnyType) {
	v.value = val
	v.isSet = true
}

func (v NullableAdditionalPropertiesAnyType) IsSet() bool {
	return v.isSet
}

func (v *NullableAdditionalPropertiesAnyType) Unset() {
	v.value = nil
	v.isSet = false
}

func NewNullableAdditionalPropertiesAnyType(val *AdditionalPropertiesAnyType) *NullableAdditionalPropertiesAnyType {
	return &NullableAdditionalPropertiesAnyType{value: val, isSet: true}
}

func (v NullableAdditionalPropertiesAnyType) MarshalJSON() ([]byte, error) {
	return json.Marshal(v.value)
}

func (v *NullableAdditionalPropertiesAnyType) UnmarshalJSON(src []byte) error {
	v.isSet = true
	return json.Unmarshal(src, &v.value)
}


