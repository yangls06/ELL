////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     IsNodeCompilable.cpp (common)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "IsNodeCompilable.h"

// model
#include "InputNode.h"
#include "OutputNode.h"

// nodes
#include "ConstantNode.h"
#include "BinaryOperationNode.h"
#include "BinaryPredicateNode.h"
#include "SumNode.h"
#include "ElementSelectorNode.h"
#include "UnaryOperationNode.h"
#include "MultiplexorNode.h"

namespace common
{
    IsNodeCompilable::IsNodeCompilable()
    {
        AddNodeType<model::InputNode<bool>>();
        AddNodeType<model::InputNode<double>>();
        AddNodeType<nodes::ConstantNode<bool>>();
        AddNodeType<nodes::ConstantNode<double>>();
        AddNodeType<nodes::BinaryOperationNode<bool>>();
        AddNodeType<nodes::BinaryOperationNode<double>>();
        AddNodeType<nodes::BinaryPredicateNode<double>>();
        AddNodeType<nodes::ElementSelectorNode<double,bool>>();
        AddNodeType<nodes::SumNode<double>>();
        AddNodeType<nodes::UnaryOperationNode<double>>();
        AddNodeType<nodes::UnaryOperationNode<bool>>();
        AddNodeType<nodes::MultiplexorNode<bool,bool>>();
        AddNodeType<nodes::MultiplexorNode<double,bool>>();
    }

    bool IsNodeCompilable::operator()(const model::Node& node)
    {
        const auto& nodeName = node.GetRuntimeTypeName();
        if(_nodeNames.find(nodeName) != _nodeNames.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}