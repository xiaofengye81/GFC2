#include "StdAfx.h"
#include "Gfc2CoedgeListBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CoedgeList.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeListBinarySerializer,"Gfc2CoedgeListB",0)

int Gfc2CoedgeListBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeList* pEnt = (Gfc2CoedgeList*)pEntity;
    int total_size = Gfc2GeometryBinarySerializer::byteSize(pEnt);

    if (pEnt->getCoedgesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoedgesCount());
    for (int i = 0; i < pEnt->getCoedgesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoedges(i));
    }

    return total_size;
}

void Gfc2CoedgeListBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeList* pEnt = (Gfc2CoedgeList*)pEntity;
    Gfc2GeometryBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getCoedgesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCoedgesCount(), output);
        for (int i = 0; i < pEnt->getCoedgesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCoedges(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2CoedgeListBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeList* pEnt = (Gfc2CoedgeList*)pEntity;
    target = Gfc2GeometryBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getCoedgesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCoedgesCount(), target);
        for (int i = 0; i < pEnt->getCoedgesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCoedges(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CoedgeListBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CoedgeList* pEnt = (Gfc2CoedgeList*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CoedgeList_Coedges)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addCoedges(value);
        }
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

