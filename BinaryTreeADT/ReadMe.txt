========================================================================
    CONSOLE APPLICATION : BinaryTreeADT Project Overview
========================================================================

AppWizard has created this BinaryTreeADT application for you.

This file contains a summary of what you will find in each of the files that
make up your BinaryTreeADT application.


BinaryTreeADT.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

BinaryTreeADT.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

BinaryTreeADT.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named BinaryTreeADT.pch and a precompiled types file named StdAfx.obj.
Tree.h,Tree.cpp
     The functions have been prototyped in Tree.h header file.
	 The functions have been defined in Tree.cpp file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
FUNCTION AVAILABLE FOR BINARY TREE:-
Addnode(integer):Add a new node to Binary Tree.Takes an integer as parameter to add it to the Tree

Delnode(integer):Deletes a node from the Binary Tree.Takes an integer as parameter to delete it from the Tree

Search(integer):Searches a number in the Binary Tree.Takes an integer as paramater to search it in the Tree.

Smallestnumber():Return smallest number from the Tree.

Root():Returns the integer value of the root node

Parent(integer):Returns the integer value the parent of the particular number that has been passed as parameter.

Left(integer):Returns the integer value the left child of the particular number that has been passed as parameter.

Right(integer):Returns the integer value the right child of the particular number that has been passed as parameter.

isEmpty():Returns 0 if Tree is empty else returns 1.

isExternal(integer):Returns 0 if the integer parameter passed is in the leaf node,else returns 1.

Depth():Returns depth of the tree.Root node is considered at depth zero.