////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     CppEmitter.h (compiler)
//  Authors:  Umesh Madan
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Types.h"
#include "IndentedTextWriter.h"

namespace emll
{
	namespace compiler
	{
		/// <summary>Helper class for emitting properly INDENTED TEXT C++ code</summary>
		class CppEmitter
		{
		public:
			CppEmitter();

			CppEmitter& Comment(const std::string& text);

			CppEmitter& Space();
			CppEmitter& NewLine();
			CppEmitter& Semicolon();
			CppEmitter& Comma();
			CppEmitter& OpenComment();
			CppEmitter& CloseComment();
			CppEmitter& OpenBrace();
			CppEmitter& CloseBrace();
			CppEmitter& OpenParan();
			CppEmitter& CloseParan();
			CppEmitter& OpenBracket();
			CppEmitter& CloseBracket();
			CppEmitter& Quote();
			CppEmitter& Question();
			CppEmitter& Colon();
			CppEmitter& Assign();
			CppEmitter& Asterisk();
			CppEmitter& Increment();
			CppEmitter& IncrementUpdate();
			CppEmitter& EndStatement();

			CppEmitter& Operator(OperatorType op);
			CppEmitter& Cmp(ComparisonType cmp);

			CppEmitter& Const();
			CppEmitter& Static();
			CppEmitter& Token(const std::string& token);
			CppEmitter& Type(const ValueType type);
			CppEmitter& Identifier(const std::string& id) { return Token(id); }

			CppEmitter& Offset(int offset);
			CppEmitter& Offset(const std::string& offsetVarName);
			CppEmitter& Dimension(int size);

			CppEmitter& Literal(const std::string& value);
			template<typename T>
			CppEmitter& Literal(T value);
			template<typename T>
			CppEmitter& Literal(const std::vector<T>& value);

			CppEmitter& Var(const ValueType type, const std::string& name);
			template<typename T>
			CppEmitter& Var(const std::string& name);
			template<typename T>
			CppEmitter& Var(const std::string& name, int size);

			CppEmitter& Var(const NamedValueType& var);
			CppEmitter& Vars(const NamedValueTypeList& vars);
			CppEmitter& DeclareFunction(const std::string& name, const ValueType returnType, const NamedValueTypeList& args);

			template<typename T>
			CppEmitter& Cmp(const std::string& varName, ComparisonType cmp, T value);

			CppEmitter& Assign(const std::string& varName);
			CppEmitter& IncrementUpdate(const std::string& varName);
			CppEmitter& AssignValueAt(const std::string& varName, const int offset);
			CppEmitter& AssignValueAt(const std::string& varName, const std::string& offsetVarName);
			CppEmitter& IncrementValueAt(const std::string& varName, const std::string& offsetVarName);

			CppEmitter& For();
			CppEmitter& If();
			CppEmitter& Else();

			CppEmitter& BeginBlock();
			CppEmitter& EndBlock();

			CppEmitter& AppendRaw(const std::string& code);
			CppEmitter& Append(CppEmitter& emitter);
			CppEmitter& Append(CppEmitter* pEmitter);
			CppEmitter& Clear();

			///<summary>Increase the indent</summary>
			CppEmitter& IncreaseIndent();
			///<summary>Decrease the indent</summary>
			CppEmitter& DecreaseIndent();
			uint32_t& Indent() { return _writer.IndentCount(); }

			std::string Code() { return _writer.ToString(); }

		private:
			CppEmitter& AppendReindent(std::string& code, int indentDelta);

		private:
			IndentedTextWriter _writer;
		};	
	}
}

#include "../tcc/CppEmitter.tcc"
