// ======================================================================
// \title  PrimitiveSerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Primitive struct
// ======================================================================

#ifndef PrimitiveSerializableAc_HPP
#define PrimitiveSerializableAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/ExternalString.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

//! Top-level annotation, line 1
//! Top-level annotation, line 2
class Primitive :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The type of mF32
    using Type_of_mF32 = F32[3];

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        sizeof(F32) * 3 +
        sizeof(F64) +
        sizeof(I16) +
        sizeof(I32) +
        sizeof(I64) +
        sizeof(I8) +
        sizeof(U16) +
        sizeof(U32) +
        sizeof(U64) +
        sizeof(U8) +
        sizeof(U8) +
        Fw::StringBase::STATIC_SERIALIZED_SIZE(80)
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    Primitive();

    //! Member constructor
    Primitive(
        const Type_of_mF32& mF32,
        F64 mF64,
        I16 mI16,
        I32 mI32,
        I64 mI64,
        I8 mI8,
        U16 mU16,
        U32 mU32,
        U64 mU64,
        U8 mU8,
        bool m_bool,
        const Fw::StringBase& m_string
    );

    //! Copy constructor
    Primitive(
        const Primitive& obj //!< The source object
    );

    //! Member constructor (scalar values for arrays)
    Primitive(
        F32 mF32,
        F64 mF64,
        I16 mI16,
        I32 mI32,
        I64 mI64,
        I8 mI8,
        U16 mU16,
        U32 mU32,
        U64 mU64,
        U8 mU8,
        bool m_bool,
        const Fw::StringBase& m_string
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    Primitive& operator=(
        const Primitive& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const Primitive& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const Primitive& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Primitive& obj //!< The object
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Member functions
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    );

#if FW_SERIALIZABLE_TO_STRING

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member mF32
    Type_of_mF32& getmF32()
    {
      return this->m_mF32;
    }

    //! Get member mF32 (const)
    const Type_of_mF32& getmF32() const
    {
      return this->m_mF32;
    }

    //! Get member mF64
    F64 getmF64() const
    {
      return this->m_mF64;
    }

    //! Get member mI16
    I16 getmI16() const
    {
      return this->m_mI16;
    }

    //! Get member mI32
    I32 getmI32() const
    {
      return this->m_mI32;
    }

    //! Get member mI64
    I64 getmI64() const
    {
      return this->m_mI64;
    }

    //! Get member mI8
    I8 getmI8() const
    {
      return this->m_mI8;
    }

    //! Get member mU16
    U16 getmU16() const
    {
      return this->m_mU16;
    }

    //! Get member mU32
    U32 getmU32() const
    {
      return this->m_mU32;
    }

    //! Get member mU64
    U64 getmU64() const
    {
      return this->m_mU64;
    }

    //! Get member mU8
    U8 getmU8() const
    {
      return this->m_mU8;
    }

    //! Get member m_bool
    bool getm_bool() const
    {
      return this->m_m_bool;
    }

    //! Get member m_string
    Fw::ExternalString& getm_string()
    {
      return this->m_m_string;
    }

    //! Get member m_string (const)
    const Fw::ExternalString& getm_string() const
    {
      return this->m_m_string;
    }

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(
        const Type_of_mF32& mF32,
        F64 mF64,
        I16 mI16,
        I32 mI32,
        I64 mI64,
        I8 mI8,
        U16 mU16,
        U32 mU32,
        U64 mU64,
        U8 mU8,
        bool m_bool,
        const Fw::StringBase& m_string
    );

    //! Set member mF32
    void setmF32(const Type_of_mF32& mF32);

    //! Set member mF64
    void setmF64(F64 mF64);

    //! Set member mI16
    void setmI16(I16 mI16);

    //! Set member mI32
    void setmI32(I32 mI32);

    //! Set member mI64
    void setmI64(I64 mI64);

    //! Set member mI8
    void setmI8(I8 mI8);

    //! Set member mU16
    void setmU16(U16 mU16);

    //! Set member mU32
    void setmU32(U32 mU32);

    //! Set member mU64
    void setmU64(U64 mU64);

    //! Set member mU8
    void setmU8(U8 mU8);

    //! Set member m_bool
    void setm_bool(bool m_bool);

    //! Set member m_string
    void setm_string(const Fw::StringBase& m_string);

  protected:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    F32 m_mF32[3];
    F64 m_mF64;
    I16 m_mI16;
    I32 m_mI32;
    I64 m_mI64;
    I8 m_mI8;
    U16 m_mU16;
    U32 m_mU32;
    U64 m_mU64;
    U8 m_mU8;
    bool m_m_bool;
    char m___fprime_ac_m_string_buffer[Fw::StringBase::BUFFER_SIZE(80)];
    Fw::ExternalString m_m_string;

};

#endif
