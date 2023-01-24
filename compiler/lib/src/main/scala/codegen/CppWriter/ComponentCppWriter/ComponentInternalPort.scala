package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.codegen._

/** Writes out C++ for component internal ports */
case class ComponentInternalPort (
  s: CppWriterState,
  aNode: Ast.Annotated[AstNode[Ast.DefComponent]]
) extends ComponentCppWriterUtils(s, aNode) {

  def getInternalPortFunctionMembers: List[CppDoc.Class.Member] = {
    if !hasInternalPorts then Nil
    else List(
      getHandlers,
      getHandlerBases
    ).flatten
  }

  private def getHandlers: List[CppDoc.Class.Member] = {
    List(
      List(
        CppDoc.Class.Member.Lines(
          CppDoc.Lines(
            List(
              CppDocHppWriter.writeAccessTag("PROTECTED"),
              CppDocWriter.writeBannerComment(
                "Internal interface handlers"
              ),
            ).flatten
          )
        ),
      ),
      internalPorts.map(p =>
        CppDoc.Class.Member.Function(
          CppDoc.Function(
            Some(
              s"Internal interface handler for ${p.getUnqualifiedName}"
            ),
            internalInterfaceHandlerName(p.getUnqualifiedName),
            getFunctionParams(p),
            CppDoc.Type("void"),
            Nil,
            CppDoc.Function.PureVirtual
          )
        )
      )
    ).flatten
  }

  private def getHandlerBases: List[CppDoc.Class.Member] = {
    List(
      List(
        CppDoc.Class.Member.Lines(
          CppDoc.Lines(
            List(
              CppDocHppWriter.writeAccessTag("PROTECTED"),
              CppDocWriter.writeBannerComment(
                "Internal interface base-class functions"
              ),
            ).flatten
          )
        ),
      ),
      internalPorts.map(p =>
        CppDoc.Class.Member.Function(
          CppDoc.Function(
            Some(
              s"Internal interface base-class function for ${p.getUnqualifiedName}"
            ),
            internalInterfaceHandlerBaseName(p.getUnqualifiedName),
            getFunctionParams(p),
            CppDoc.Type("void"),
            Nil
          )
        )
      )
    ).flatten
  }

}