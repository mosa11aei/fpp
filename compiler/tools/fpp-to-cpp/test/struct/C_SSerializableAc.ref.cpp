// ======================================================================
// \title  C_SSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for C_S struct
// ======================================================================

#include "C_SSerializableAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

C_S ::
  C_S() :
    Serializable(),
    m_x(0)
{

}

C_S ::
  C_S(U32 x) :
    Serializable(),
    m_x(x)
{

}

C_S ::
  C_S(const C_S& obj) :
    Serializable(),
    m_x(obj.m_x)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

C_S& C_S ::
  operator=(const C_S& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_x);
  return *this;
}

bool C_S ::
  operator==(const C_S& obj) const
{
  return (this->m_x == obj.m_x);
}

bool C_S ::
  operator!=(const C_S& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const C_S& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus C_S ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus C_S ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void C_S ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "x = %" PRIu32 ""
    " )";

  sb.format(
    formatString,
    this->m_x
  );
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void C_S ::
  set(U32 x)
{
  this->m_x = x;
}

void C_S ::
  setx(U32 x)
{
  this->m_x = x;
}
