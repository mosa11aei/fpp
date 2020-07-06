package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.util._
import scala.language.implicitConversions

/** Writes out the locations of definitions */
object LocateDefsFppWriter extends AstVisitor with LineUtils {

  case class State(
    /** The base directory for constructing location specifiers */
    val baseDir: Option[String],
    /** The list of enclosing module names */
    val moduleNameList: List[Name.Unqualified] = Nil
  )

  override def default(s: State) = Nil

  override def defAbsTypeAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefAbsType]]
  ) = {
    val (_, node, _) = aNode
    val data = node.getData
    writeSpecLoc(s, Ast.SpecLoc.Type, data.name, node)
  }

  override def defArrayAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefArray]]
  ) = {
    val (_, node, _) = aNode
    val data = node.getData
    writeSpecLoc(s, Ast.SpecLoc.Type, data.name, node)
  }

  override def defConstantAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefConstant]]
  ) = {
    val (_, node, _) = aNode
    val data = node.getData
    writeSpecLoc(s, Ast.SpecLoc.Constant, data.name, node)
  }

  override def defEnumAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefEnum]]
  ) = {
    val (_, node, _) = aNode
    val data = node.getData
    writeSpecLoc(s, Ast.SpecLoc.Type, data.name, node)
  }

  override def defModuleAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefModule]]
  ) = {
    val (_, node, _) = aNode
    val Ast.DefModule(name, members) = node.getData
    val s1 = s.copy(moduleNameList = name :: s.moduleNameList)
    members.flatMap(matchModuleMember(s1, _))
  }

  override def defStructAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefStruct]]
  ) = {
    val (_, node, _) = aNode
    val data = node.getData
    writeSpecLoc(s, Ast.SpecLoc.Type, data.name, node)
  }

  override def transUnit(s: State, tu: Ast.TransUnit) = 
    tu.members.flatMap(matchModuleMember(s, _))

  private def writeSpecLoc[T](
    s: State,
    kind: Ast.SpecLoc.Kind,
    name: String,
    node: AstNode[T]
  ): List[Line] = {
    val loc = Locations.get(node.getId)
    loc.file match {
      case File.Path(path) => {
        val nodeList = (name :: s.moduleNameList).reverse.map(s => AstNode.create(s))
        val qualIdentNode = AstNode.create(Ast.QualIdent.fromNodeList(nodeList))
        val baseDir = s.baseDir match {
          case Some(dir) => dir
          case None => ""
        }
        val baseDirPath = java.nio.file.Paths.get(baseDir).toAbsolutePath
        val relativePath = baseDirPath.relativize(path)
        val fileNode = AstNode.create(relativePath.normalize.toString)
        val specLocNode = AstNode.create(Ast.SpecLoc(kind, qualIdentNode, fileNode))
        val specLocAnnotatedNode = (Nil, specLocNode, Nil)
        FppWriter.specLocAnnotatedNode((), specLocAnnotatedNode)
      }
      case File.StdIn => Nil
    }
  }

  type In = State

  type Out = List[Line]

}