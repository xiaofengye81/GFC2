#include "StdAfx.h"
#include "Gfc2CylinderBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Cylinder.h"

OBJECTBUF_IMP_OBJECT(Gfc2CylinderBinarySerializer,"Gfc2CylinderB",0)

int Gfc2CylinderBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Cylinder* pEnt = (Gfc2Cylinder*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRangeV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeV());
    }

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    if (pEnt->hasDirX())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirX());
    }

    if (pEnt->hasDirY())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirY());
    }

    if (pEnt->hasDirZ())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirZ());
    }

    if (pEnt->hasPos())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPos());
    }

    return total_size;
}

void Gfc2CylinderBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Cylinder* pEnt = (Gfc2Cylinder*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRangeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getRangeV(), output);
    }

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getCurve(), output);
    }

    if (pEnt->hasDirX())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getDirX(), output);
    }

    if (pEnt->hasDirY())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getDirY(), output);
    }

    if (pEnt->hasDirZ())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getDirZ(), output);
    }

    if (pEnt->hasPos())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getPos(), output);
    }

}

google::protobuf::uint8* Gfc2CylinderBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Cylinder* pEnt = (Gfc2Cylinder*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRangeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getRangeV(), target);
    }

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getCurve(), target);
    }

    if (pEnt->hasDirX())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getDirX(), target);
    }

    if (pEnt->hasDirY())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getDirY(), target);
    }

    if (pEnt->hasDirZ())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getDirZ(), target);
    }

    if (pEnt->hasPos())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getPos(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CylinderBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Cylinder* pEnt = (Gfc2Cylinder*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Cylinder_RangeV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Cylinder_Curve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCurve(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Cylinder_DirX)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirX(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Cylinder_DirY)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirY(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Cylinder_DirZ)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirZ(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Cylinder_Pos)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPos(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

