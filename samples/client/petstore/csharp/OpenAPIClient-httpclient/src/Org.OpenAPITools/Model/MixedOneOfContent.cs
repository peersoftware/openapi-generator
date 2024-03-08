/*
 * OpenAPI Petstore
 *
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * Generated by: https://github.com/openapitools/openapi-generator.git
 */


using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.IO;
using System.Runtime.Serialization;
using System.Text;
using System.Text.RegularExpressions;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;
using Newtonsoft.Json.Linq;
using System.ComponentModel.DataAnnotations;
using FileParameter = Org.OpenAPITools.Client.FileParameter;
using OpenAPIDateConverter = Org.OpenAPITools.Client.OpenAPIDateConverter;
using OpenAPIClientUtils = Org.OpenAPITools.Client.ClientUtils;
using System.Reflection;

namespace Org.OpenAPITools.Model
{
    /// <summary>
    /// Mixed oneOf types for testing
    /// </summary>
    [JsonConverter(typeof(MixedOneOfContentJsonConverter))]
    [DataContract(Name = "MixedOneOf_content")]
    public partial class MixedOneOfContent : AbstractOpenAPISchema, IEquatable<MixedOneOfContent>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="MixedOneOfContent" /> class
        /// with the <see cref="string" /> class
        /// </summary>
        /// <param name="actualInstance">An instance of string.</param>
        public MixedOneOfContent(string actualInstance)
        {
            this.IsNullable = false;
            this.SchemaType= "oneOf";
            this.ActualInstance = actualInstance ?? throw new ArgumentException("Invalid instance found. Must not be null.");
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedOneOfContent" /> class
        /// with the <see cref="bool" /> class
        /// </summary>
        /// <param name="actualInstance">An instance of bool.</param>
        public MixedOneOfContent(bool actualInstance)
        {
            this.IsNullable = false;
            this.SchemaType= "oneOf";
            this.ActualInstance = actualInstance;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedOneOfContent" /> class
        /// with the <see cref="int" /> class
        /// </summary>
        /// <param name="actualInstance">An instance of int.</param>
        public MixedOneOfContent(int actualInstance)
        {
            this.IsNullable = false;
            this.SchemaType= "oneOf";
            this.ActualInstance = actualInstance;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedOneOfContent" /> class
        /// with the <see cref="decimal" /> class
        /// </summary>
        /// <param name="actualInstance">An instance of decimal.</param>
        public MixedOneOfContent(decimal actualInstance)
        {
            this.IsNullable = false;
            this.SchemaType= "oneOf";
            this.ActualInstance = actualInstance;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedOneOfContent" /> class
        /// with the <see cref="MixedSubId" /> class
        /// </summary>
        /// <param name="actualInstance">An instance of MixedSubId.</param>
        public MixedOneOfContent(MixedSubId actualInstance)
        {
            this.IsNullable = false;
            this.SchemaType= "oneOf";
            this.ActualInstance = actualInstance ?? throw new ArgumentException("Invalid instance found. Must not be null.");
        }


        private Object _actualInstance;

        /// <summary>
        /// Gets or Sets ActualInstance
        /// </summary>
        public override Object ActualInstance
        {
            get
            {
                return _actualInstance;
            }
            set
            {
                if (value.GetType() == typeof(MixedSubId))
                {
                    this._actualInstance = value;
                }
                else if (value.GetType() == typeof(bool))
                {
                    this._actualInstance = value;
                }
                else if (value.GetType() == typeof(decimal))
                {
                    this._actualInstance = value;
                }
                else if (value.GetType() == typeof(int))
                {
                    this._actualInstance = value;
                }
                else if (value.GetType() == typeof(string))
                {
                    this._actualInstance = value;
                }
                else
                {
                    throw new ArgumentException("Invalid instance found. Must be the following types: MixedSubId, bool, decimal, int, string");
                }
            }
        }

        /// <summary>
        /// Get the actual instance of `string`. If the actual instance is not `string`,
        /// the InvalidClassException will be thrown
        /// </summary>
        /// <returns>An instance of string</returns>
        public string GetString()
        {
            return (string)this.ActualInstance;
        }

        /// <summary>
        /// Get the actual instance of `bool`. If the actual instance is not `bool`,
        /// the InvalidClassException will be thrown
        /// </summary>
        /// <returns>An instance of bool</returns>
        public bool GetBool()
        {
            return (bool)this.ActualInstance;
        }

        /// <summary>
        /// Get the actual instance of `int`. If the actual instance is not `int`,
        /// the InvalidClassException will be thrown
        /// </summary>
        /// <returns>An instance of int</returns>
        public int GetInt()
        {
            return (int)this.ActualInstance;
        }

        /// <summary>
        /// Get the actual instance of `decimal`. If the actual instance is not `decimal`,
        /// the InvalidClassException will be thrown
        /// </summary>
        /// <returns>An instance of decimal</returns>
        public decimal GetDecimal()
        {
            return (decimal)this.ActualInstance;
        }

        /// <summary>
        /// Get the actual instance of `MixedSubId`. If the actual instance is not `MixedSubId`,
        /// the InvalidClassException will be thrown
        /// </summary>
        /// <returns>An instance of MixedSubId</returns>
        public MixedSubId GetMixedSubId()
        {
            return (MixedSubId)this.ActualInstance;
        }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class MixedOneOfContent {\n");
            sb.Append("  ActualInstance: ").Append(this.ActualInstance).Append("\n");
            sb.Append("}\n");
            return sb.ToString();
        }

        /// <summary>
        /// Returns the JSON string presentation of the object
        /// </summary>
        /// <returns>JSON string presentation of the object</returns>
        public override string ToJson()
        {
            return JsonConvert.SerializeObject(this.ActualInstance, MixedOneOfContent.SerializerSettings);
        }

        /// <summary>
        /// Converts the JSON string into an instance of MixedOneOfContent
        /// </summary>
        /// <param name="jsonString">JSON string</param>
        /// <returns>An instance of MixedOneOfContent</returns>
        public static MixedOneOfContent FromJson(string jsonString)
        {
            MixedOneOfContent newMixedOneOfContent = null;

            if (string.IsNullOrEmpty(jsonString))
            {
                return newMixedOneOfContent;
            }
            int match = 0;
            List<string> matchedTypes = new List<string>();

            try
            {
                // if it does not contains "AdditionalProperties", use SerializerSettings to deserialize
                if (typeof(MixedSubId).GetProperty("AdditionalProperties") == null)
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<MixedSubId>(jsonString, MixedOneOfContent.SerializerSettings));
                }
                else
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<MixedSubId>(jsonString, MixedOneOfContent.AdditionalPropertiesSerializerSettings));
                }
                matchedTypes.Add("MixedSubId");
                match++;
            }
            catch (Exception exception)
            {
                // deserialization failed, try the next one
                System.Diagnostics.Debug.WriteLine(string.Format("Failed to deserialize `{0}` into MixedSubId: {1}", jsonString, exception.ToString()));
            }

            try
            {
                // if it does not contains "AdditionalProperties", use SerializerSettings to deserialize
                if (typeof(bool).GetProperty("AdditionalProperties") == null)
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<bool>(jsonString, MixedOneOfContent.SerializerSettings));
                }
                else
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<bool>(jsonString, MixedOneOfContent.AdditionalPropertiesSerializerSettings));
                }
                matchedTypes.Add("bool");
                match++;
            }
            catch (Exception exception)
            {
                // deserialization failed, try the next one
                System.Diagnostics.Debug.WriteLine(string.Format("Failed to deserialize `{0}` into bool: {1}", jsonString, exception.ToString()));
            }

            try
            {
                // if it does not contains "AdditionalProperties", use SerializerSettings to deserialize
                if (typeof(decimal).GetProperty("AdditionalProperties") == null)
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<decimal>(jsonString, MixedOneOfContent.SerializerSettings));
                }
                else
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<decimal>(jsonString, MixedOneOfContent.AdditionalPropertiesSerializerSettings));
                }
                matchedTypes.Add("decimal");
                match++;
            }
            catch (Exception exception)
            {
                // deserialization failed, try the next one
                System.Diagnostics.Debug.WriteLine(string.Format("Failed to deserialize `{0}` into decimal: {1}", jsonString, exception.ToString()));
            }

            try
            {
                // if it does not contains "AdditionalProperties", use SerializerSettings to deserialize
                if (typeof(int).GetProperty("AdditionalProperties") == null)
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<int>(jsonString, MixedOneOfContent.SerializerSettings));
                }
                else
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<int>(jsonString, MixedOneOfContent.AdditionalPropertiesSerializerSettings));
                }
                matchedTypes.Add("int");
                match++;
            }
            catch (Exception exception)
            {
                // deserialization failed, try the next one
                System.Diagnostics.Debug.WriteLine(string.Format("Failed to deserialize `{0}` into int: {1}", jsonString, exception.ToString()));
            }

            try
            {
                // if it does not contains "AdditionalProperties", use SerializerSettings to deserialize
                if (typeof(string).GetProperty("AdditionalProperties") == null)
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<string>(jsonString, MixedOneOfContent.SerializerSettings));
                }
                else
                {
                    newMixedOneOfContent = new MixedOneOfContent(JsonConvert.DeserializeObject<string>(jsonString, MixedOneOfContent.AdditionalPropertiesSerializerSettings));
                }
                matchedTypes.Add("string");
                match++;
            }
            catch (Exception exception)
            {
                // deserialization failed, try the next one
                System.Diagnostics.Debug.WriteLine(string.Format("Failed to deserialize `{0}` into string: {1}", jsonString, exception.ToString()));
            }

            if (match == 0)
            {
                throw new InvalidDataException("The JSON string `" + jsonString + "` cannot be deserialized into any schema defined.");
            }
            else if (match > 1)
            {
                throw new InvalidDataException("The JSON string `" + jsonString + "` incorrectly matches more than one schema (should be exactly one match): " + String.Join(",", matchedTypes));
            }

            // deserialization is considered successful at this point if no exception has been thrown.
            return newMixedOneOfContent;
        }

        /// <summary>
        /// Returns true if objects are equal
        /// </summary>
        /// <param name="input">Object to be compared</param>
        /// <returns>Boolean</returns>
        public override bool Equals(object input)
        {
            return OpenAPIClientUtils.compareLogic.Compare(this, input as MixedOneOfContent).AreEqual;
        }

        /// <summary>
        /// Returns true if MixedOneOfContent instances are equal
        /// </summary>
        /// <param name="input">Instance of MixedOneOfContent to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(MixedOneOfContent input)
        {
            return OpenAPIClientUtils.compareLogic.Compare(this, input).AreEqual;
        }

        /// <summary>
        /// Gets the hash code
        /// </summary>
        /// <returns>Hash code</returns>
        public override int GetHashCode()
        {
            unchecked // Overflow is fine, just wrap
            {
                int hashCode = 41;
                if (this.ActualInstance != null)
                    hashCode = hashCode * 59 + this.ActualInstance.GetHashCode();
                return hashCode;
            }
        }

        /// <summary>
        /// To validate all properties of the instance
        /// </summary>
        /// <param name="validationContext">Validation context</param>
        /// <returns>Validation Result</returns>
        IEnumerable<System.ComponentModel.DataAnnotations.ValidationResult> IValidatableObject.Validate(ValidationContext validationContext)
        {
            yield break;
        }
    }

    /// <summary>
    /// Custom JSON converter for MixedOneOfContent
    /// </summary>
    public class MixedOneOfContentJsonConverter : JsonConverter
    {
        /// <summary>
        /// To write the JSON string
        /// </summary>
        /// <param name="writer">JSON writer</param>
        /// <param name="value">Object to be converted into a JSON string</param>
        /// <param name="serializer">JSON Serializer</param>
        public override void WriteJson(JsonWriter writer, object value, JsonSerializer serializer)
        {
            writer.WriteRawValue((string)(typeof(MixedOneOfContent).GetMethod("ToJson").Invoke(value, null)));
        }

        /// <summary>
        /// To convert a JSON string into an object
        /// </summary>
        /// <param name="reader">JSON reader</param>
        /// <param name="objectType">Object type</param>
        /// <param name="existingValue">Existing value</param>
        /// <param name="serializer">JSON Serializer</param>
        /// <returns>The object converted from the JSON string</returns>
        public override object ReadJson(JsonReader reader, Type objectType, object existingValue, JsonSerializer serializer)
        {
            switch(reader.TokenType) 
            {
                case JsonToken.String: 
                    return new MixedOneOfContent(Convert.ToString(reader.Value));
                case JsonToken.Boolean: 
                    return new MixedOneOfContent(Convert.ToBoolean(reader.Value));
                case JsonToken.Integer: 
                    return new MixedOneOfContent(Convert.ToInt32(reader.Value));
                case JsonToken.Float: 
                    return new MixedOneOfContent(Convert.ToDecimal(reader.Value));
                case JsonToken.StartObject:
                    return MixedOneOfContent.FromJson(JObject.Load(reader).ToString(Formatting.None));
                case JsonToken.StartArray:
                    return MixedOneOfContent.FromJson(JArray.Load(reader).ToString(Formatting.None));
                default:
                    return null;
            }
        }

        /// <summary>
        /// Check if the object can be converted
        /// </summary>
        /// <param name="objectType">Object type</param>
        /// <returns>True if the object can be converted</returns>
        public override bool CanConvert(Type objectType)
        {
            return false;
        }
    }

}
