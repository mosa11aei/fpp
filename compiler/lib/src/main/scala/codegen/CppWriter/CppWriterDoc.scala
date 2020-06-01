package fpp.compiler.codegen

/** A C++ Writer document representing an .hpp file backed by zero or more
 *  .cpp files. */
case class CppWriterDoc(
  hppFileName: String,
  includeGuard: String,
  members: List[CppWriterDoc.Member]
)

object CppWriterDoc {

  /** A C++ class */
  case class Class(name: String, members: List[Class.Member])
  object Class {
    sealed trait Member
    object Member {
      case class Class(c: CppWriterDoc.Class) extends Member
      case class Constructor(constructor: CppWriterDoc.Class.Constructor) extends Member
      case class Lines(lines: CppWriterDoc.Lines) extends Member
      case class Function(function: CppWriterDoc.Function) extends Member
    }
    case class Constructor(
      name: String,
      params: List[Function.Param],
      initializers: List[String],
      body: List[Line]
    )
  }

  /** A C++ function, either standalone or inside a class */
  case class Function(
    name: String,
    params: List[Function.Param],
    retType: Type,
    body: List[Line],
    constQualifier: Function.ConstQualifier = Function.NonConst,
    virtualQualifier: Function.VirtualQualifier = Function.NonVirtual
  )
  case object Function {
    case class Param(
      name: String,
      t: Type,
      comment: Option[String]
    )
    sealed trait ConstQualifier
    case object Const extends ConstQualifier
    case object NonConst extends ConstQualifier
    sealed trait VirtualQualifier
    case object NonVirtual extends VirtualQualifier
    case object PureVirtual extends VirtualQualifier
    case object Virtual extends VirtualQualifier
  }


  /** A list of uninterpreted lines of C++ code */
  case class Lines(lines: List[Line], output: Lines.Output = Lines.Hpp)
  object Lines {
    sealed trait Output
    case object Hpp extends Output
    case class Cpp(cppFile: String) extends Output
    case class Both(cppFile: String) extends Output
  }

  /** A C++ namespace */
  case class Namespace(name: String, members: List[Namespace.Member])
  object Namespace {
    type Member = CppWriterDoc.Member
  }

  /** A C++ type. The .cpp spelling of the type can be different from the .hpp type. 
   *  E.g., the .cpp version may need more qualifiers. */
  case class Type(
    hppType: String,
    cppType: Option[String] = None
  )

  /** A CppWriter document member */
  sealed trait Member
  object Member {
    case class Class(c: CppWriterDoc.Class) extends Member
    case class Lines(lines: CppWriterDoc.Lines) extends Member
    case class Function(function: CppWriterDoc.Function) extends Member
    case class Namespace(namespace: CppWriterDoc.Namespace) extends Member
  }

}
