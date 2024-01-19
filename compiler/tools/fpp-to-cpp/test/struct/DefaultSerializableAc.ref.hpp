// ======================================================================
// \title  DefaultSerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Default struct
// ======================================================================

#ifndef DefaultSerializableAc_HPP
#define DefaultSerializableAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

class Default :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // StringSize40 class
    // ----------------------------------------------------------------------

    class StringSize40 :
      public Fw::StringBase
    {

      public:

        enum {
          //! The size of the string length plus the size of the string buffer
          SERIALIZED_SIZE = sizeof(FwBuffSizeType) + 40
        };

        //! Default constructor
        StringSize40();

        //! Char array constructor
        StringSize40(const char* src);

        //! String base constructor
        StringSize40(const Fw::StringBase& src);

        //! Copy constructor
        StringSize40(const StringSize40& src);

        //! Destructor
        ~StringSize40();

        //! Copy assignment operator
        StringSize40& operator=(const StringSize40& other);

        //! String base assignment operator
        StringSize40& operator=(const Fw::StringBase& other);

        //! char* assignment operator
        StringSize40& operator=(const char* other);

        //! Retrieves char buffer of string
        const char* toChar() const;

        NATIVE_UINT_TYPE getCapacity() const;

      private:

        char m_buf[40]; //!< Buffer for string storage

    };

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        sizeof(U32) +
        StringSize40::SERIALIZED_SIZE +
        sizeof(F64)
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    Default();

    //! Member constructor
    Default(
        U32 memberU32,
        const StringSize40& memberString,
        F64 memberF64
    );

    //! Copy constructor
    Default(
        const Default& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    Default& operator=(
        const Default& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const Default& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const Default& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Default& obj //!< The object
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

    //! Get member memberU32
    U32 getmemberU32() const
    {
      return this->m_memberU32;
    }

    //! Get member memberString
    StringSize40& getmemberString()
    {
      return this->m_memberString;
    }

    //! Get member memberString (const)
    const StringSize40& getmemberString() const
    {
      return this->m_memberString;
    }

    //! Get member memberF64
    F64 getmemberF64() const
    {
      return this->m_memberF64;
    }

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(
        U32 memberU32,
        const StringSize40& memberString,
        F64 memberF64
    );

    //! Set member memberU32
    void setmemberU32(U32 memberU32);

    //! Set member memberString
    void setmemberString(const StringSize40& memberString);

    //! Set member memberF64
    void setmemberF64(F64 memberF64);

  protected:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    U32 m_memberU32;
    StringSize40 m_memberString;
    F64 m_memberF64;

};

#endif
