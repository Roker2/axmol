#include "JSONBasic.h"
#include "base/Utils.h"
#include "platform/Common.h"
#include "platform/FileUtils.h"

#include "rapidjson/prettywriter.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

NS_AX_EXT_BEGIN

JSONBasic::JSONBasic(std::string_view filePath)
    : _filePath(filePath)
{
    init();
}

bool JSONBasic::init()
{
    if (_initialized)
        return true;

    if (_filePath.empty())
    {
        AXLOGERROR("JSONBasic::init file path is empty");
        return false;
    }

    if (FileUtils::getInstance()->isFileExist(_filePath))
    {
        auto data_str = FileUtils::getInstance()->getStringFromFile(_filePath);

        _doc.SetObject();

        _doc.Parse(data_str.c_str());

        if (_doc.HasParseError())
        {
            AXLOGERROR("JSONBasic::init load json file: %s failed", _filePath.c_str());
            return false;
        }
    }

    _initialized = true;
    return true;
}

// Getters
bool JSONBasic::getBoolForKey(const char* key)
{
    return getBoolForKey(key, false);
}

bool JSONBasic::getBoolForKey(const char* key, bool defaultValue)
{
    if (_doc.HasMember(key))
        return _doc[key].GetBool();
    return defaultValue;
}

int JSONBasic::getIntegerForKey(const char* key)
{
    return getIntegerForKey(key, 0);
}

int JSONBasic::getIntegerForKey(const char* key, int defaultValue)
{
    if (_doc.HasMember(key))
        return _doc[key].GetInt();
    return defaultValue;
}

int64_t JSONBasic::getLargeIntForKey(const char* key)
{
    return getLargeIntForKey(key, 0);
}

int64_t JSONBasic::getLargeIntForKey(const char* key, int64_t defaultValue)
{
    if (_doc.HasMember(key))
        return _doc[key].GetInt64();
    return defaultValue;
}

float JSONBasic::getFloatForKey(const char* key)
{
    return getFloatForKey(key, 0.0f);
}

float JSONBasic::getFloatForKey(const char* key, float defaultValue)
{
    if (_doc.HasMember(key))
        return _doc[key].GetFloat();
    return defaultValue;
}

double JSONBasic::getDoubleForKey(const char* key)
{
    return getDoubleForKey(key, 0.0);
}

double JSONBasic::getDoubleForKey(const char* key, double defaultValue)
{
    if (_doc.HasMember(key))
        return _doc[key].GetDouble();
    return defaultValue;
}

std::string_view JSONBasic::getStringForKey(const char* key)
{
    return getStringForKey(key, "");
}

std::string_view JSONBasic::getStringForKey(const char* key, std::string_view defaultValue)
{
    if (_doc.HasMember(key))
        return _doc[key].GetString();
    return defaultValue;
}

// Setters
void JSONBasic::setBoolForKey(const char* key, bool value)
{
    if (!key)
        return;
    if (_doc.HasMember(key))
    {
        _doc[key].SetBool(value);
    }
    else
    {
        _doc.AddMember(rapidjson::GenericStringRef(key), rapidjson::Value(value), _doc.GetAllocator());
    }
    flush();
}

void JSONBasic::setIntegerForKey(const char* key, int value)
{
    if (!key)
        return;
    if (_doc.HasMember(key))
    {
        _doc[key].SetInt(value);
    }
    else
    {
        _doc.AddMember(rapidjson::GenericStringRef(key), rapidjson::Value(value), _doc.GetAllocator());
    }
    flush();
}

void JSONBasic::setLargeIntForKey(const char* key, int64_t value)
{  // check key
    if (!key)
        return;
    if (_doc.HasMember(key))
    {
        _doc[key].SetInt64(value);
    }
    else
    {
        _doc.AddMember(rapidjson::GenericStringRef(key), rapidjson::Value(value), _doc.GetAllocator());
    }
    flush();
}

void JSONBasic::setFloatForKey(const char* key, float value)
{
    if (!key)
        return;
    if (_doc.HasMember(key))
    {
        _doc[key].SetFloat(value);
    }
    else
    {
        _doc.AddMember(rapidjson::GenericStringRef(key), rapidjson::Value(value), _doc.GetAllocator());
    }
    flush();
}

void JSONBasic::setDoubleForKey(const char* key, double value)
{
    if (!key)
        return;
    if (_doc.HasMember(key))
    {
        _doc[key].SetDouble(value);
    }
    else
    {
        _doc.AddMember(rapidjson::GenericStringRef(key), rapidjson::Value(value), _doc.GetAllocator());
    }
    flush();
}

void JSONBasic::setStringForKey(const char* key, const char* value)
{
    if (!key)
        return;

    if (_doc.HasMember(key))
    {
        _doc[key].SetString(rapidjson::GenericStringRef(value));
    }
    else
    {
        _doc.AddMember(rapidjson::GenericStringRef(key), rapidjson::GenericStringRef(value), _doc.GetAllocator());
    }
    flush();
}

// Delete
void JSONBasic::deleteValueForKey(const char* key)
{
    if (!this->_doc.HasMember(key))
        return;

    this->_doc.RemoveMember(key);
    flush();
}

// Save
void JSONBasic::flush(bool pretty /*= false*/)
{
    rapidjson::StringBuffer buffer;

    if (pretty)
    {
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        _doc.Accept(writer);
    }
    else
    {
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        _doc.Accept(writer);
    }
    FileUtils::getInstance()->writeStringToFile(buffer.GetString(), _filePath);
}

// Reset
void JSONBasic::reset()
{
    _doc.RemoveAllMembers();
    flush();
}

NS_AX_EXT_END
