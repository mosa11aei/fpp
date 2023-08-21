// ======================================================================
// \title  QueuedSerialTester.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for QueuedSerial component test harness implementation class
// ======================================================================

#include "QueuedSerialTester.hpp"

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

QueuedSerialTester ::
  QueuedSerialTester() :
    QueuedSerialGTestBase("QueuedSerialTester", QueuedSerialTester::MAX_HISTORY_SIZE),
    component("QueuedSerial")
{
  this->initComponents();
  this->connectPorts();
}

QueuedSerialTester ::
  ~QueuedSerialTester()
{

}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

void QueuedSerialTester ::
  toDo()
{
  // TODO
}

// ----------------------------------------------------------------------
// Handlers for typed from ports
// ----------------------------------------------------------------------

void QueuedSerialTester ::
  from_typedOut_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

F32 QueuedSerialTester ::
  from_typedReturnOut_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO return
}

// ----------------------------------------------------------------------
// Handlers for serial from ports
// ----------------------------------------------------------------------

void QueuedSerialTester ::
  from_serialOut_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{
  // TODO
}