#pragma once


class DataStream;
namespace ch_utility{
    namespace serialize {

    class Serializable
    {
        public:
        virtual void serialize(DataStream& stream) const =0;
        virtual bool unSerialize(DataStream& stream) = 0;
    };

#define SERIALIZE(...)                        \
    void serialize(DataStream &stream) const  \
    {                                         \
    char type = DataStream::CUSTOM;           \
    stream.write((char *)&type, sizeof(char));\
        stram.write_args(__VA_ARGS__);        \
    }                                         \
    void serialize(DataStream &stream) const  \
    {                                         \
    char type;                                \
    stream.read(&type, sizeof(char));         \
    if (type != DataStream::CUSTOM)           \
    {                                         \
        return false                     ;     \
    }                                         \
    stream.read_args(__VA_ARGS__);            \
    return true;                              \
    }

    }
}
