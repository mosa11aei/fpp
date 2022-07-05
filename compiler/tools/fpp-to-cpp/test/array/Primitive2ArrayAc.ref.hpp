// ======================================================================
// \title  Primitive2ArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Primitive2 array
// ======================================================================

#ifndef M_Primitive2ArrayAc_HPP
#define M_Primitive2ArrayAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

#include "FppConstantsAc.hpp"

namespace M {

  //! An array of primitives with specified default value and format string
  class Primitive2 :
    public Fw::Serializable
  {

    public:

      // ----------------------------------------------------------------------
      // Types
      // ----------------------------------------------------------------------

      //! The element type
      typedef F32 ElementType;

    public:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      enum {
        //! The size of the array
        SIZE = 5,
        //! The size of the serial representation
        SERIALIZED_SIZE = SIZE * sizeof(ElementType),
      };

    public:

      // ----------------------------------------------------------------------
      // Constructors
      // ----------------------------------------------------------------------

      //! Constructor (default value)
      Primitive2();

      //! Constructor (user-provided value)
      Primitive2(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Constructor (single element)
      Primitive2(
          const ElementType& e //!< The element
      );

      //! Constructor (multiple elements)
      Primitive2(
          const ElementType (&e1), //!< Element 1
          const ElementType (&e2), //!< Element 2
          const ElementType (&e3), //!< Element 3
          const ElementType (&e4), //!< Element 4
          const ElementType (&e5) //!< Element 5
      );

      //! Copy Constructor
      Primitive2(
          const Primitive2& obj //!< The source object
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
      Primitive2& operator=(
          const Primitive2& obj //!< The source object
      );

      //! Copy assignment operator (raw array)
      Primitive2& operator=(
          const ElementType (&a)[SIZE] //!< The source array
      );

      //! Copy assignment operator (single element)
      Primitive2& operator=(
          const ElementType& e //!< The element
      );

      //! Equality operator
      bool operator==(
          const Primitive2& obj //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const Primitive2& obj //!< The other object
      ) const;

#ifdef BUILD_UT

      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const Primitive2& obj //!< The object
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

#if FW_ARRAY_TO_STRING || BUILD_UT

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
