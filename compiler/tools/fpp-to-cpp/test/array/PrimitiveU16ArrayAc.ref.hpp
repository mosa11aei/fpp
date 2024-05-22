// ======================================================================
// \title  PrimitiveU16ArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PrimitiveU16 array
// ======================================================================

#ifndef M_PrimitiveU16ArrayAc_HPP
#define M_PrimitiveU16ArrayAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/ExternalString.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

namespace M {

  class PrimitiveU16 :
    public Fw::Serializable
  {

    public:

      // ----------------------------------------------------------------------
      // Types
      // ----------------------------------------------------------------------

      //! The element type
      using ElementType = U16;

    public:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      enum {
        //! The size of the array
        SIZE = 3,
        //! The serialized size of each element
        ELEMENT_SERIALIZED_SIZE = sizeof(U16),
        //! The size of the serial representation
        SERIALIZED_SIZE = SIZE * ELEMENT_SERIALIZED_SIZE
      };

    public:

      // ----------------------------------------------------------------------
      // Constructors
      // ----------------------------------------------------------------------

      //! Constructor (default value)
      PrimitiveU16();

      //! Constructor (user-provided value)
      PrimitiveU16(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Constructor (single element)
      PrimitiveU16(
          const ElementType& e //!< The element
      );

      //! Constructor (multiple elements)
      PrimitiveU16(
          const ElementType& e1, //!< Element 1
          const ElementType& e2, //!< Element 2
          const ElementType& e3 //!< Element 3
      );

      //! Copy Constructor
      PrimitiveU16(
          const PrimitiveU16& obj //!< The source object
      );

    public:

      // ----------------------------------------------------------------------
      // Operators
      // ----------------------------------------------------------------------

      //! Subscript operator
      ElementType& operator[](
          const U32 i //!< The subscript index
      );

      //! Const subscript operator
      const ElementType& operator[](
          const U32 i //!< The subscript index
      ) const;

      //! Copy assignment operator (object)
      PrimitiveU16& operator=(
          const PrimitiveU16& obj //!< The source object
      );

      //! Copy assignment operator (raw array)
      PrimitiveU16& operator=(
          const ElementType (&a)[SIZE] //!< The source array
      );

      //! Copy assignment operator (single element)
      PrimitiveU16& operator=(
          const ElementType& e //!< The element
      );

      //! Equality operator
      bool operator==(
          const PrimitiveU16& obj //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const PrimitiveU16& obj //!< The other object
      ) const;

#ifdef BUILD_UT

      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const PrimitiveU16& obj //!< The object
      );

#endif

    public:

      // ----------------------------------------------------------------------
      // Public member functions
      // ----------------------------------------------------------------------

      //! Serialization
      Fw::SerializeStatus serialize(
          Fw::SerializeBufferBase& buffer //!< The serial buffer
      ) const;

      //! Deserialization
      Fw::SerializeStatus deserialize(
          Fw::SerializeBufferBase& buffer //!< The serial buffer
      );

#if FW_ARRAY_TO_STRING

      //! Convert array to string
      void toString(
          Fw::StringBase& sb //!< The StringBase object to hold the result
      ) const;

#endif

    private:

      // ----------------------------------------------------------------------
      // Member variables
      // ----------------------------------------------------------------------

      //! The array elements
      ElementType elements[SIZE];

  };

}

#endif
