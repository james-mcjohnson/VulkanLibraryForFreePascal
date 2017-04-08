{
  Vulkan Library for FreePascal
  Copyright (c) 2017 by James McJohnson

  <Public Service Announcement>:

    "For I am not ashamed of the Good News of Christ, for it is the power of God for salvation for everyone who believes..." - Romans 1:16
    "For God so loved the world, that He gave His only begotten Son, that whosoever believeth in Him should not perish, but have everlasting life." - John 3:16

    Hear: "So faith comes by hearing, and hearing by the word of God." - Romans 10:17
    Believe: "...for unless you believe that I am He, you will die in your sins." - John 8:24
    Repent: "The times of ignorance therefore God overlooked. But now He commands that all people everywhere should repent, because He has appointed a day in which
     He will judge the world in righteousness by the Man Whom He has ordained; of which He has given assurance to all men, in that He has raised Him from the dead.” - Acts 17:30-31
    Confess: "Everyone therefore who confesses Me before men, him I will also confess before My Father Who is in heaven.
      But whoever denies Me before men, him I will also deny before My Father Who is in heaven." - Matthew 10:32-33
    Be Baptized: "Go, and make disciples of all nations, baptizing them in the name of the Father and of the Son and of the Holy Spirit" - Matthew 28:19

  </Public Service Announcement>:

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
  persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice, the above public service announcement (in its entirety), and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
}

unit vulkan_vk_xml_to_pas;

{$mode objfpc}{$H+}
{$packset 4}

interface

uses
  Classes, Dialogs, SysUtils, ComCtrls, fgl, DOM, XMLRead;

const
  COMMENT_POSITION = 60;
  extBase      = 1000000000;
  extBlockSize = 1000;

type
  TVulkanHeaderIncludeFiles = record
    ConstantsAndTypes: String;
    FunctionVariables: String;
    FunctionAssignments: String;
    DBGFunctionDeclarations: String;
    DBGFunctionImplementations: String;
    GlobalInitialization: String;
  end;


  { TCreateChildList }

  generic TCreateChildList<T> = class(specialize TFPGObjectList<T>)
    function CreateChild(Level: Integer = -1): T;
    function GetListing(IncludeLastDelimiter: Boolean; aDelimiter: String; NoCRLF: Boolean = False): String;
    function FindIdentifier(aIdentifier: String): T;
    function FindIdentifierIndex(aIdentifier: String): Integer;
    procedure MoveIdentifierBefore(aIdentifier1, aIdentifier2: String);
  end;

  TComment = class;
  TExtension = class;

  { TListObj }

  TListObj = class
    private
      FLevel: Integer;
    public
      Identifier: String;
      CommentInternal: String;
      AcceptLateComment: Boolean;
      PreComment, PostComment: TComment;
      function GetPreComment: String;
      function GetPostComment(curlen: Integer): String;
      function SpaceOutPostComment(curlen: Integer; CommentText: String): String;
      function GetListing(Delimiter: String; NoCRLF: Boolean = False): String;
      function GetInfo(Delimiter: String): String; virtual;
      function GetExtraInfo: String; virtual;
  end;

  TPointerDepth = class(TListObj)
    NeededPointerDepth: Integer;
  end;
  TPointerDepthList = specialize TCreateChildList<TPointerDepth>;

  { TComment }

  TComment = class(TListObj)
    private
      FUsed: Boolean;
      FPrinted: Boolean;
    public
      xmlComment: Boolean;
      Text: String;
      PreviousObject, NextObject: TListObj;
      function GetInfo(Delimiter: String): String; override;
      procedure LoadFromXMLCommentNode(const Node: TDOMNode);
  end;
  TCommentList = specialize TCreateChildList<TComment>;

  { TConstant }

  TConstant = class(TListObj)
    Value: String;
    function GetInfo(Delimiter: String): String; override;
    procedure LoadFromEnumNode(Node: TDOMNode);
    procedure LoadFromVendorNode(Node: TDOMNode);
    procedure LoadFromTagNode(Node: TDOMNode);
  end;
  TConstantList = specialize TCreateChildList<TConstant>;

  { TType }

  TType = class(TListObj)
    BaseType: String;
    NeededPointerDepth: Integer;
    function GetInfo(Delimiter: String): String; override;
    function GetExtraInfo: String; override;
    procedure LoadFromBitmaskNode(Node: TDOMNode);
    procedure LoadFromHandleNode(Node: TDOMNode);
  end;
  TTypeList = specialize TCreateChildList<TType>;

  { TField }

  TField = class(TListObj)
    BaseType: String;
    SubType: String;
    ArrayDims: String;
    ConstFlag: Boolean;
    OptionalFlag: Boolean;
    procedure LoadFromNode(Node: TDOMNode);
    function GetInfo(Delimiter: String): String; override;
  end;
  TFieldList = specialize TCreateChildList<TField>;

  { TFunctionDefinition }

  TFunctionDefinition = class(TListObj)
    ReturnType: String;
    ParameterList: TFieldList;
    procedure LoadFromNode(Node: TDOMNode);
    function GetInfo(Delimiter: String): String; override;
    constructor Create;
    destructor Destroy; override;
  end;
  TFunctionDefinitionList = specialize TCreateChildList<TFunctionDefinition>;

  { TCommand }

  TCommand = class(TListObj)
    Extension: TExtension;

    SuccessCodes: String;
    ErrorCodes: String;
    Queues: String;
    RenderPass: String;
    CmdBufferLevel: String;

    ReturnType: String;
    ParameterList: TFieldList;
    procedure LoadFromNode(Node: TDOMNode);
    function GetInfo(Delimiter: String): String; override;

    function GetFunctionPointerDeclaration: String;
    function GetFunctionDeclaration(aClassName: String; IncludeCallingConvention: Boolean=True; IncludeProtect: Boolean = True): String;
    function GetFunctionCheck(aClassName: String): String;
    function GetFunctionVariable: String;
    function GetFunctionAssignment: String;
    constructor Create;
    destructor Destroy; override;
  end;
  TCommandList = specialize TCreateChildList<TCommand>;

  { TStruct }

  TStruct = class(TListObj)
    Extension: TExtension;
    UnionFlag: Boolean;
    FieldList: TFieldList;
    NeededPointerDepth: Integer;

    procedure GetFields(Node: TDOMNode);
    function GetInfo(Delimiter: String): String; override;
    procedure LoadFromNode(Node: TDOMNode);
    constructor Create;
    destructor Destroy; override;
  end;
  TStructList = specialize TCreateChildList<TStruct>;

  { TEnum }

  TEnum = class(TListObj)
    BitMaskFlag: Boolean;

    Values: TConstantList;
    ExtraConstants: TConstantList;

    NeededPointerDepth: Integer;

    procedure LoadFromNode(Node: TDOMNode);
    function GetInfo(Delimiter: String): String; override;
    constructor Create;
    destructor Destroy; override;
  end;
  TEnumList = specialize TCreateChildList<TEnum>;

  { TExtension }

  TExtension = class(TListObj)
    ProtectDefine: String; // VK_USE_PLATFORM_WIN32_KHR, VK_USE_PLATFORM_XLIB_KHR, etc.
    Number: Integer;
    Types: TTypeList;
    Commands: TCommandList;
    procedure LoadFromNode(Node: TDOMNode);
    constructor Create;
    destructor Destroy; override;
  end;
  TExtensionList = specialize TCreateChildList<TExtension>;

procedure XML2Tree(XMLDoc:TXMLDocument; TreeView:TTreeView);
function GetPascalHeaderFromFile(aXMLFileName: String; var VHIF: TVulkanHeaderIncludeFiles): String;
function GetPascalHeader(XMLDoc: TXMLDocument; var VHIF: TVulkanHeaderIncludeFiles): String;
function AddGlobalType(aIdentifier, aType: String; UseGlobalTypePos: Boolean = False): TType;
procedure IncIndent;
procedure DecIndent;
procedure HandleNode(Node: TDOMNode);
procedure HandleChildren(Node: TDOMNode);
procedure HandleTypeNode(Node: TDOMNode);
function EnumSort(const Item1, Item2: TConstant): Integer;

procedure SaveVulkanIncludeFiles(SourceXMLFilename: String);

var
  BaseTypes: TStringList;
  ReservedWords: TStringList;
  GlobalConstants: TConstantList;
  GlobalTypes: TTypeList;
  GlobalStructs: TStructList;
  GlobalCommands: TCommandList;
  GlobalFunctionDefinitions: TFunctionDefinitionList;
  GlobalEnums: TEnumList;
  GlobalComments: TCommentList;
  GlobalExtensions: TExtensionList;
  GlobalPointerDepthsList: TPointerDepthList;
  LastObj: TListObj;
  LastComment: TComment;
  GlobalInitialization: String = '';
  GlobalIndent: String = '';
  GlobalTypePos: Integer = 0;
  GlobalUseIndent: Boolean = True;


implementation

function GetPointerDepth(Identifier: String; NeededPointerDepth: Integer): String;
var ii: Integer;
    a, b: String;
begin
  Result := '';
  a := Identifier;
  b := Identifier;
  if a[1] = 'T' then
    Delete(a, 1, 1);
  a := 'P' + a;
  for ii := 1 to NeededPointerDepth do
  begin
    Result += GlobalIndent + a + ' = ^' + b + ';' + #13#10;
    b := a;
    a := 'P' + a;
  end;
end;


function IndentString(ss: String): String;
var aStringList: TStringList;
    ii: Integer;
begin
  aStringList := TStringList.Create;
  aStringList.Text := ss;
  Result := '';
  for ii := 0 to aStringList.Count - 1 do
    Result += GlobalIndent + aStringList.Strings[ii] + #13#10;
  FreeAndNil(aStringList);
end;

procedure InitBaseTypes;
begin
  BaseTypes := TStringList.Create;
  with BaseTypes do
  begin
    Add('HINSTANCE');
    Add('HWND');
  end;
end;

procedure InitReservedWords;
begin
  ReservedWords := TStringList.Create;
  with ReservedWords do
  begin
    Add('and');
    Add('array');
    Add('asm');
    Add('begin');
    Add('break');
    Add('case');
    Add('const');
    Add('constructor');
    Add('continue');
    Add('destructor');
    Add('div');
    Add('do');
    Add('downto');
    Add('else');
    Add('end');
    Add('false');
    Add('file');
    Add('for');
    Add('function');
    Add('goto');
    Add('if');
    Add('implementation');
    Add('in');
    Add('inline');
    Add('interface');
    Add('label');
    Add('mod');
    Add('nil');
    Add('not');
    Add('object');
    Add('of');
    Add('on');
    Add('operator');
    Add('or');
    Add('packed');
    Add('procedure');
    Add('program');
    Add('record');
    Add('repeat');
    Add('set');
    Add('shl');
    Add('shr');
    Add('string');
    Add('then');
    Add('to');
    Add('true');
    Add('type');
    Add('unit');
    Add('until');
    Add('uses');
    Add('var');
    Add('while');
    Add('with');
    Add('xor');
    Add('as');
    Add('class');
    Add('dispose');
    Add('except');
    Add('exit');
    Add('exports');
    Add('finalization');
    Add('finally');
    Add('inherited');
    Add('initialization');
    Add('is');
    Add('library');
    Add('new');
    Add('on');
    Add('out');
    Add('property');
    Add('raise');
    Add('self');
    Add('threadvar');
    Add('try');
    Add('absolute');
    Add('abstract');
    Add('alias');
    Add('assembler');
    Add('cdecl');
    Add('cppdecl');
    Add('default');
    Add('export');
    Add('external');
    Add('forward');
    Add('generic');
    Add('index');
    Add('local');
    Add('name');
    Add('nostackframe');
    Add('oldfpccall');
    Add('override');
    Add('pascal');
    Add('private');
    Add('protected');
    Add('public');
    Add('published');
    Add('read');
    Add('register');
    Add('reintroduce');
    Add('safecall');
    Add('softfloat');
    Add('specialize');
    Add('stdcall');
    Add('virtual');
    Add('write');
  end;
end;

procedure XML2Tree(XMLDoc:TXMLDocument; TreeView:TTreeView);

  // Local function that outputs all node attributes as a string
  function GetNodeAttributesAsString(pNode: TDOMNode):string;
  var i: integer;
  begin
    Result:='';
    if pNode.HasAttributes then
    begin
      Result := '(';
      for i := 0 to pNode.Attributes.Length -1 do
        with pNode.Attributes[i] do
          Result := Result + format('%s="%s", ', [NodeName, NodeValue]);
      SetLength(Result, Length(Result) - 2);
      Result := Result + ')';
    end;

    // Remove leading and trailing spaces
    Result:=Trim(Result);
  end;

  // Recursive function to process a node and all its child nodes

  procedure ParseXML(Node:TDOMNode; TreeNode: TTreeNode);
  var NodeInfo: String;
      NodeValue: String;
  begin
    // Exit procedure if no more nodes to process
    if Node = nil then Exit;

    NodeValue := Node.NodeValue;
    if (Node.NodeType = ELEMENT_NODE) and (NodeValue <> '') then
      NodeValue := NodeValue;

    // Add node to TreeView
    case Node.NodeType of
      ELEMENT_NODE: NodeInfo := 'Element: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      ATTRIBUTE_NODE: NodeInfo := 'Attribute: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      TEXT_NODE: NodeInfo := 'Text: ' + Node.NodeValue;
      CDATA_SECTION_NODE: NodeInfo := 'CData: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      COMMENT_NODE: NodeInfo := 'Comment: ' + Node.NodeValue;
      ENTITY_REFERENCE_NODE: NodeInfo := 'ENTITY_REFERENCE_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      ENTITY_NODE: NodeInfo := 'ENTITY_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      PROCESSING_INSTRUCTION_NODE: NodeInfo := 'PROCESSING_INSTRUCTION_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      DOCUMENT_NODE: NodeInfo := 'DOCUMENT_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      DOCUMENT_TYPE_NODE: NodeInfo := 'DOCUMENT_TYPE_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      DOCUMENT_FRAGMENT_NODE: NodeInfo := 'DOCUMENT_FRAGMENT_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
      NOTATION_NODE: NodeInfo := 'NOTATION_NODE: ' + Trim(Node.NodeName+' '+ GetNodeAttributesAsString(Node)+ Node.NodeValue);
    end;
    TreeNode := TreeView.Items.AddChild(TreeNode, NodeInfo);

    // Process all child nodes
    Node := Node.FirstChild;
    while Node <> Nil do
    begin
      ParseXML(Node, TreeNode);
      Node := Node.NextSibling;
    end;
  end;

begin
  TreeView.Items.Clear;
  ParseXML(XMLDoc.DocumentElement,nil);
end;

function GetPascalHeaderFromFile(aXMLFileName: String; var VHIF: TVulkanHeaderIncludeFiles): String;
var Doc: TXMLDocument;
begin
  try
    ReadXMLFile(Doc, aXMLFileName);
    Result := GetPascalHeader(Doc, VHIF);
  finally
    FreeAndNil(Doc);
  end;
end;

function GetAttribute(aNode: TDOMNode; aAttributeName: String): String;
var aItem: TDOMNode;
begin
  Result := '';
  if not Assigned(aNode.Attributes) then Exit;
  aItem := aNode.Attributes.GetNamedItem(aAttributeName);
  if not Assigned(aItem) then Exit;
  Result := Trim(aItem.NodeValue);
end;

function GetChildNode(aNode: TDOMNode; aNodeName: String): TDOMNode;
begin
  Result := aNode.FirstChild;
  while Result <> Nil do
  begin
    if Result.NodeName = aNodeName then Exit;
    Result := Result.NextSibling;
  end;
  Result := nil;
end;

function GetChildNodeContents(aNode: TDOMNode; aNodeName: String): String;
begin
  Result := '';
  aNode := GetChildNode(aNode, aNodeName);
  if not Assigned(aNode) then Exit;
  Result := aNode.TextContent;
end;

{function FixChars(Ident: String): String;
var i, len: integer;
begin
  len := length(Ident);
  if len <> 0 then
  begin
   result := Ident[1] in ['A'..'Z', 'a'..'z', '_'];
   i := 1;
   while (result) and (i < len) do begin
      i := i + 1;
      result := result and (Ident[i] in ['A'..'Z', 'a'..'z', '0'..'9', '_']);
      end ;
   end ;
end; }

function FixReservedWords(aName: String): String;
begin
  Result := aName;
  if ReservedWords.IndexOf(Lowercase(aName)) <> -1 then
  begin
    Result := Result + '_';
  end;
end;

procedure PostProcessPointerDepths;
var aStruct: TStruct;
    aPointerDepth: TPointerDepth;
    aTypeObj: TType;
    aEnum: TEnum;
    Found: Boolean;
begin
  for aPointerDepth in GlobalPointerDepthsList do
  with aPointerDepth do
  begin
    Found := False;
    aStruct := GlobalStructs.FindIdentifier(Identifier);
    Found := Assigned(aStruct);
    if Found and (NeededPointerDepth > aStruct.NeededPointerDepth) then
      aStruct.NeededPointerDepth := NeededPointerDepth;
    if not Found then
    begin
      aTypeObj := GlobalTypes.FindIdentifier(Identifier);
      Found := Assigned(aTypeObj);
      if Found and (NeededPointerDepth > aTypeObj.NeededPointerDepth) then
        aTypeObj.NeededPointerDepth := NeededPointerDepth;
    end;
    if not Found then
    begin
      aEnum := GlobalEnums.FindIdentifier(Identifier);
      Found := Assigned(aEnum);
      if Found and (NeededPointerDepth > aEnum.NeededPointerDepth) then
        aEnum.NeededPointerDepth := NeededPointerDepth;
    end;
//    if not Found then
//      raise Exception.Create('"' + Identifier + '" not found');
  end;
end;

function PostProcessDependencies: Boolean;
var aStruct: TStruct;
  MainIndex, aIndex: Integer;
  aField: TField;
begin
  Result := False;
  // go through each field in the structs, if a referenced type is found with higher index, move it above current struct
  for aStruct in GlobalStructs do
  begin
    MainIndex := GlobalStructs.IndexOf(aStruct);

    for aField in aStruct.FieldList do
    begin
      aIndex := GlobalStructs.FindIdentifierIndex(aField.SubType);
      if aIndex > MainIndex then
      begin
        Result := True;
        GlobalStructs.Move(aIndex, MainIndex);
        MainIndex := MainIndex + 1;
      end;
    end;
  end;
end;

function TranslateTypeToPascal(PointerDepth: Integer; aType: String): String;
const Pointers = 'PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP';

  procedure AddGlobalPointerDepth(TypeName: String);
  var aPointerDepth: TPointerDepth;
  begin
    aPointerDepth := GlobalPointerDepthsList.FindIdentifier(TypeName);
    if not Assigned(aPointerDepth) then
    begin
      aPointerDepth := GlobalPointerDepthsList.CreateChild;
      aPointerDepth.Identifier := TypeName;
    end;
    if PointerDepth > aPointerDepth.NeededPointerDepth then
      aPointerDepth.NeededPointerDepth := PointerDepth;
  end;
begin
  if aType = 'void' then
  begin
//    Assert(PointerDepth > 0, '');
    Dec(PointerDepth);
    Result := '';
    if PointerDepth > 0 then
      Result := Copy(Pointers, 1, PointerDepth);
     Result += 'Pointer';
  end
  else if aType = 'HINSTANCE' then
    Result := 'HINST'
  else if BaseTypes.IndexOf(aType) <> -1 then
  begin
    Result := Copy(Pointers, 1, PointerDepth) + aType;
    AddGlobalPointerDepth(aType);
  end
  else
  begin
    if PointerDepth > 0 then
    begin
      Result := Copy(Pointers, 1, PointerDepth) + aType;
      AddGlobalPointerDepth('T' + aType);
    end
    else Result := 'T' + aType;
  end;
end;

function AddConditionalDefine(aCondition, aDefine: String): String;
begin
  Result := '';
  Result += '{$IFDEF ' + aCondition + '}' + #13#10;
  Result += '  {$DEFINE ' + aDefine + '}' + #13#10;
  Result += '{$ENDIF ' + aCondition + '}';
end;

function AddConditional(aCondition, aText: String): String;
begin
  Result := '';
  Result := '{$IFDEF ' + aCondition + '}' + aText + '{$ENDIF ' + aCondition + '}';
end;

function GetFunctionDeclarations(aClassName: String): String;
var aCommand: TCommand;
begin
  Result := '';
  for aCommand in GlobalCommands do
    Result += aCommand.GetFunctionDeclaration(aClassName, False);
end;

function GetExtensionsEnumsAndNames: String;
var aExtension: TExtension;
begin
  Result := '';

  Result += GlobalIndent + 'TvkExtension = (' + #13#10;
  IncIndent;
  for aExtension in GlobalExtensions do
    Result += GlobalIndent + aExtension.Identifier + ', ' + #13#10;
  SetLength(Result, Length(Result) - 4);

  Result += #13#10;

  DecIndent;
  Result += GlobalIndent + ');' + #13#10#13#10;

//  Result += GlobalIndent + 'TSetof_vkExtension = set of TvkExtension;' + #13#10#13#10;
  Result += GlobalIndent + 'TvkExtensions = set of TvkExtension;' + #13#10#13#10;


  Result += GlobalIndent + 'const' + #13#10;
  Result += GlobalIndent + 'vkExtension_Names: array[TvkExtension] of String = (' + #13#10;

  IncIndent;
  for aExtension in GlobalExtensions do
    Result += GlobalIndent + '''' + aExtension.Identifier + ''', ' + #13#10;
  SetLength(Result, Length(Result) - 4);
  Result += #13#10;

  DecIndent;
  Result += GlobalIndent + ');' + #13#10#13#10;

  Result += 'type' + #13#10;


end;

function GetFunctionVariables: String;
var aCommand: TCommand;
begin
  Result := '';
  for aCommand in GlobalCommands do
    Result += aCommand.GetFunctionVariable;
end;

function GetFunctionAssignments: String;
var aCommand: TCommand;
begin
  Result := '';
  for aCommand in GlobalCommands do
    Result += aCommand.GetFunctionAssignment;
end;

function GetFunctionChecks(aClassName: String): String;
var aCommand: TCommand;
begin
  Result := '';
  for aCommand in GlobalCommands do
    Result += aCommand.GetFunctionCheck(aClassName);
end;

procedure CreateEnumConstants(Node: TDOMNode);
begin
  Node := Node.FirstChild;

  while Assigned(Node) do
  begin
    if Node.NodeName = 'enum' then GlobalConstants.CreateChild.LoadFromEnumNode(Node);
    Node := Node.NextSibling;
  end;
end;


var structcount: Integer = 0;


function GetPascalHeader(XMLDoc: TXMLDocument; var VHIF: TVulkanHeaderIncludeFiles): String;
var Registry: TDOMNode;
    ContinueFlag: Boolean;

  procedure AddLine(ss: String; AddLineIndent: Boolean = True);
  begin
    if AddLineIndent then Result := Result + GlobalIndent;
    Result := Result + ss + #13#10;
  end;

  procedure AddLine(var Result: String; ss: String; AddLineIndent: Boolean = True);
  begin
    if AddLineIndent then Result := Result + GlobalIndent;
    Result := Result + ss + #13#10;
  end;

const
    VulkanInterfaceDBG = 'Tvk_Instance_DBG';
begin
  GlobalIndent := '';
  GlobalConstants := TConstantList.Create(True);
  GlobalTypes := TTypeList.Create(True);
  GlobalStructs := TStructList.Create(True);
  GlobalCommands := TCommandList.Create(True);
  GlobalFunctionDefinitions := TFunctionDefinitionList.Create(True);
  GlobalEnums := TEnumList.Create(True);
  GlobalComments := TCommentList.Create(True);
  GlobalExtensions := TExtensionList.Create(True);
  GlobalPointerDepthsList := TPointerDepthList.Create(True);

  InitBaseTypes;
  InitReservedWords;
  Result := '';

  Registry := XMLDoc.DocumentElement;
  Assert(Registry.NodeName = 'registry', '');

  // Process all child nodes
  HandleChildren(Registry);

  PostProcessPointerDepths;

  ContinueFlag := True;
  while ContinueFlag do
  begin
    ContinueFlag := PostProcessDependencies;
  end;


  Result := '';
  VHIF.ConstantsAndTypes := '';
  VHIF.FunctionVariables := '';
  VHIF.FunctionAssignments := '';
  VHIF.DBGFunctionDeclarations := '';
  VHIF.DBGFunctionImplementations := '';
  VHIF.GlobalInitialization := '';

  AddLine(VHIF.ConstantsAndTypes, GlobalEnums.GetListing(True, ';'));
  AddLine(VHIF.ConstantsAndTypes, 'const');
  IncIndent;
  AddLine(VHIF.ConstantsAndTypes, GlobalConstants.GetListing(True, ';'));
  AddLine(VHIF.ConstantsAndTypes, 'type');
  AddLine(VHIF.ConstantsAndTypes, GlobalTypes.GetListing(True, ';'));
  AddLine(VHIF.ConstantsAndTypes, GetExtensionsEnumsAndNames, False);
  AddLine(VHIF.ConstantsAndTypes, GlobalFunctionDefinitions.GetListing(True, ';'));
  AddLine(VHIF.ConstantsAndTypes, GlobalStructs.GetListing(True, ';'));
  AddLine(VHIF.ConstantsAndTypes, GlobalCommands.GetListing(True, ';'));

  IncIndent;
  AddLine(VHIF.FunctionVariables, GetFunctionVariables, False);
  AddLine(VHIF.DBGFunctionDeclarations, GetFunctionDeclarations(''), False);
  DecIndent;

  IncIndent;
  IncIndent;
  AddLine(VHIF.FunctionAssignments, GetFunctionAssignments, False);
  DecIndent;
  DecIndent;

  AddLine(VHIF.DBGFunctionImplementations, GetFunctionChecks(VulkanInterfaceDBG), False);
  GlobalIndent := '';
  if GlobalInitialization <> '' then
  begin
    AddLine('initialization');
    AddLine(VHIF.GlobalInitialization, GlobalInitialization);
  end;
  AddLine('end.');
//  Result += GlobalComments.GetListing(True, '');

  FreeAndNil(BaseTypes);
  FreeAndNil(ReservedWords);
  FreeAndNil(GlobalConstants);
  FreeAndNil(GlobalTypes);
  FreeAndNil(GlobalStructs);
  FreeAndNil(GlobalCommands);
  FreeAndNil(GlobalFunctionDefinitions);
  FreeAndNil(GlobalEnums);
  FreeAndNil(GlobalComments);
  FreeAndNil(GlobalExtensions);
  FreeAndNil(GlobalPointerDepthsList);
end;

function AddGlobalType(aIdentifier, aType: String; UseGlobalTypePos: Boolean): TType;
begin
  if UseGlobalTypePos then
  begin
    Result := GlobalTypes.CreateChild(GlobalTypePos);
    Inc(GlobalTypePos);
  end
  else Result := GlobalTypes.CreateChild;
  Result.Identifier := aIdentifier;
  Result.BaseType := aType;
end;

procedure IncIndent;
begin
  GlobalIndent += '  ';
end;

procedure DecIndent;
begin
  SetLength(GlobalIndent, Length(GlobalIndent) - 2);
end;

{ TCommand }

procedure TCommand.LoadFromNode(Node: TDOMNode);
var aNode: TDOMNode;
begin
  SuccessCodes := GetAttribute(Node, 'successcodes');
  ErrorCodes := GetAttribute(Node, 'errorcodes');
  Queues := GetAttribute(Node, 'queues');
  RenderPass := GetAttribute(Node, 'renderpass');
  CmdBufferLevel := GetAttribute(Node, 'cmdbufferlevel');

  Node := Node.FirstChild;
  Assert(Node.NodeName = 'proto', '');
  aNode := Node.FirstChild;
  Assert(aNode.NodeName = 'type', '');
  ReturnType := GetChildNodeContents(Node, 'type');
  if ReturnType = 'void' then ReturnType := ''
  else ReturnType := TranslateTypeToPascal(0, ReturnType);
  aNode := aNode.NextSibling;
  Assert(aNode.NodeName = 'name', '');
  Identifier := GetChildNodeContents(Node, 'name');
  aNode := aNode.NextSibling;
  Assert(not Assigned(aNode));

  if (SuccessCodes <> '') or (ErrorCodes <> '') then
    if ReturnType <> 'TVkResult' then
      raise Exception.Create('Found returntype "' + ReturnType + '"');

  Node := Node.NextSibling;
  while Assigned(Node) do
  begin
    case Node.NodeName of
      'param': ParameterList.CreateChild.LoadFromNode(Node);
      'validity', 'implicitexternsyncparams': begin end;
      '#comment':
      begin
          if not Assigned(LastComment) then
          begin
            LastComment := GlobalComments.CreateChild; //TComment.Create;
            LastComment.LoadFromXMLCommentNode(Node);
          end;
      end
      else
        try
          raise Exception.Create(Node.NodeName);
        except
        end;
    end;
    Node := Node.NextSibling;
  end;

end;

function TCommand.GetInfo(Delimiter: String): String;
begin
  Result := GetFunctionPointerDeclaration;
end;

function TCommand.GetFunctionPointerDeclaration: String;
begin
  Result := '';
  if Assigned(Extension) then
    Result += '{$IFDEF ' + Extension.ProtectDefine + '}' + #13#10;
  Result += GlobalIndent;

  Result += 'T' + Identifier + ' = ';
  if ReturnType = '' then Result += 'procedure('
  else Result += 'function(';
  Result += #13#10;

  IncIndent;
  Result += ParameterList.GetListing(False, ';');
  DecIndent;
  Result += GlobalIndent + ')';
  if ReturnType <> '' then Result += ': ' + ReturnType;
  Result += '; {$IFDEF CDECL}cdecl{$ELSE}stdcall{$ENDIF};' + #13#10;

  if Assigned(Extension) then
    Result += '{$ENDIF ' + Extension.ProtectDefine + '}' + #13#10;
end;

function TCommand.GetFunctionDeclaration(aClassName: String; IncludeCallingConvention: Boolean; IncludeProtect: Boolean): String;
var oldUseIndent: Boolean;
begin
  Result := '';
  if IncludeProtect and Assigned(Extension) then
    Result += '{$IFDEF ' + Extension.ProtectDefine + '}' + #13#10;

  oldUseIndent := GlobalUseIndent;
  GlobalUseIndent := False;
  Result += GlobalIndent;

  if ReturnType = '' then Result += 'procedure '
  else Result += 'function ';
  if aClassName <> '' then Result += aClassName + '.';
  Result += Identifier + '(';
  Result += ParameterList.GetListing(False, '; ', True);
  Result += ')';
  if ReturnType <> '' then Result += ': ' + ReturnType;
  Result += ';';
  if IncludeCallingConvention then Result += ' {$IFDEF CDECL}cdecl{$ELSE}stdcall{$ENDIF};';
  Result += #13#10;
  GlobalUseIndent := oldUseIndent;

  if IncludeProtect and Assigned(Extension) then
    Result += '{$ENDIF ' + Extension.ProtectDefine + '}' + #13#10;
end;

function TCommand.GetFunctionCheck(aClassName: String): String;
var aField: TField;

  function BreakApartList(ss: String): TStringList;
  begin
    Result := TStringList.Create;
    ExtractStrings([','], [#1..' ', '_'], PChar(ss), Result);
  end;
var EnumStr: String;
  aList: TStringList;
begin
  Result := '';
  if Assigned(Extension) then
    Result += '{$IFDEF ' + Extension.ProtectDefine + '}' + #13#10;
  Result += GetFunctionDeclaration(aClassName, False, False);
  if ReturnType = 'TVkResult' then
    Result += GlobalIndent + 'var ErrorStr: String;' + #13#10;
  Result += GlobalIndent + 'begin' + #13#10;
  IncIndent;
  Result += GlobalIndent;
  if ReturnType <> '' then
    Result += 'Result := ';
  Result += 'Vulkan_Interface.' + Identifier + '(';
  for aField in ParameterList do
    Result += aField.Identifier + ', ';

  SetLength(Result, Length(Result) - 2);

  Result += ');' + #13#10;

  if ReturnType = 'TVkResult' then
  begin
    if SuccessCodes <> '' then
    begin
      aList := BreakApartList(SuccessCodes);
      Result += GlobalIndent + 'if ';
      for EnumStr in aList do
        Result += '(Result = ' + EnumStr + ') or ';
      SetLength(Result, Length(Result) - 3);
      Result += 'then Exit;' + #13#10;
      FreeAndNil(aList);
    end;

    Result += GlobalIndent + 'WriteStr(ErrorStr, Result);' + #13#10;
    if ErrorCodes <> '' then
    begin
      aList := BreakApartList(ErrorCodes);
      Result += GlobalIndent + 'if ';
      for EnumStr in aList do
        Result += '(Result = ' + EnumStr + ') or ';
      SetLength(Result, Length(Result) - 3);
      Result += 'then ' + #13#10;
      Result += GlobalIndent + 'begin' + #13#10;
      IncIndent;
      Result += GlobalIndent + 'raise Exception.Create(''' + Identifier + ' returned "'' + ErrorStr + ''"'');' + #13#10;
      Result += GlobalIndent + 'Exit;' + #13#10;
      DecIndent;
      Result += GlobalIndent + 'end;' + #13#10;
      FreeAndNil(aList);
    end;

    Result += GlobalIndent + 'raise Exception.Create(''' + Identifier + ' returned unexpected value"'' + ErrorStr + ''"'');' + #13#10;
  end;

  DecIndent;
  Result += GlobalIndent + 'end;' + #13#10#13#10;
  if Assigned(Extension) then
    Result += '{$ENDIF ' + Extension.ProtectDefine + '}' + #13#10;
end;

function TCommand.GetFunctionVariable: String;
begin
  Result := '';
  if Assigned(Extension) then
    Result += '{$IFDEF ' + Extension.ProtectDefine + '}' + #13#10;
  Result += GlobalIndent + Identifier + ': T' + Identifier + '{$IFDEF VULKAN_FLAT} = nil{$ENDIF};' + #13#10;
  if Assigned(Extension) then
    Result += '{$ENDIF ' + Extension.ProtectDefine + '}' + #13#10;
end;

function TCommand.GetFunctionAssignment: String;
begin
  Result := '';
  case Identifier of
    'vkGetInstanceProcAddr', 'vkCreateInstance', 'vkEnumerateInstanceExtensionProperties', 'vkEnumerateInstanceLayerProperties':
      begin
        // these should already be loaded, so do nothing
      end;
    else
    begin
      if Assigned(Extension) then
        Result += '{$IFDEF ' + Extension.ProtectDefine + '}' + #13#10;
      Result += GlobalIndent + Identifier + ' := T' + Identifier + '(GetProcAddress_vulkan(''' + Identifier + '''));' + #13#10;
      if Assigned(Extension) then
        Result += '{$ENDIF ' + Extension.ProtectDefine + '}' + #13#10;
    end;
  end;
end;

constructor TCommand.Create;
begin
  ParameterList := TFieldList.Create(True);
end;

destructor TCommand.Destroy;
begin
  FreeAndNil(ParameterList);
  inherited Destroy;
end;

{ TExtension }

procedure TExtension.LoadFromNode(Node: TDOMNode);
var strName, strValue, strExtends, strDir, strOffset, strBitPos: String;
    aEnum: TEnum;
    aCommand: TCommand;
    aStruct: TStruct;
begin
  Identifier := GetAttribute(Node, 'name');
  ProtectDefine := GetAttribute(Node, 'protect');
  Number := StrToInt(GetAttribute(Node, 'number'));
  Node := Node.FirstChild;
  Assert(Node.NodeName = 'require', '');
  Node := Node.FirstChild;
  while Assigned(Node) do
  begin
    strName := GetAttribute(Node, 'name');
    case LowerCase(Node.NodeName) of
      'enum':
        begin
          strValue := GetAttribute(Node, 'value');
          strExtends := GetAttribute(Node, 'extends');
          if strValue <> '' then
            with GlobalConstants.CreateChild do
            begin
              Identifier := strName;
              Value := StringReplace(strValue, '"', '''', [rfIgnoreCase, rfReplaceAll]);
            end
          else if strExtends <> '' then
          begin
            strDir := GetAttribute(Node, 'dir');
            strOffset := GetAttribute(Node, 'offset');
            strBitPos := GetAttribute(Node, 'bitpos');
            aEnum := GlobalEnums.FindIdentifier('T' + strExtends);
            Assert(Assigned(aEnum), '');
            with aEnum.Values.CreateChild do
            begin
              Identifier := strName;
              if strOffset <> '' then
                Value := strDir + IntToStr(extBase + (Number-1)*extBlockSize + StrToInt(strOffset))
              else if strBitPos <> '' then
                Value := strBitPos;
            end;

          end
          else
            case strName of
              'VK_MAX_DEVICE_GROUP_SIZE_KHX','VK_LUID_SIZE_KHX', 'VK_QUEUE_FAMILY_EXTERNAL_KHX':
              begin
                // These are merely associating a previously created enum with the extension
              end;
            else
              ShowMessage('Unhandled extension enum: "' + strName + '". Assuming that this declaration merely associates a previously created enum with this extension.');
              raise Exception.Create('unhandled extension enum');
          end;
        end;
      'type':
        if ProtectDefine <> '' then
        begin
          aStruct := GlobalStructs.FindIdentifier('T' + strName);
          if Assigned(aStruct) then
            aStruct.Extension := Self;
        end;
      'command':
        if ProtectDefine <> '' then
        begin
          aCommand := GlobalCommands.FindIdentifier(strName);
          if Assigned(aCommand) then
            aCommand.Extension := Self;
        end;
    end;
    Node := Node.NextSibling;
  end;
end;

constructor TExtension.Create;
begin
  Commands := TCommandList.Create(True);
  Types := TTypeList.Create(True);
end;

destructor TExtension.Destroy;
begin
  FreeAndNil(Types);
  FreeAndNil(Commands);
  inherited Destroy;
end;

{ TListObj }

function TListObj.GetPreComment: String;
begin
  Result := '';
  if Assigned(PreComment) then
  begin
    Result += PreComment.GetListing('');
    PreComment.FPrinted := True;
  end;
end;

const spaces = '                                                                                                           ';
function TListObj.GetPostComment(curlen: Integer): String;
begin
  Result := '';
  if Assigned(PostComment) then
  begin
    Result := SpaceOutPostComment(curlen, PostComment.Text);
    PostComment.FPrinted := True;
  end;
end;

function TListObj.SpaceOutPostComment(curlen: Integer; CommentText: String): String;
begin
  Result := '';
  Result += Copy(spaces, 1, COMMENT_POSITION - curlen);
  Result += ' // ' + CommentText;
end;

function TListObj.GetListing(Delimiter: String; NoCRLF: Boolean): String;
var ss: String;
begin
  Result := GetPreComment;
  ss := GetInfo(Delimiter);
  Result += ss;
  Result += GetPostComment(Length(ss));
  if not NoCRLF then
    Result += #13#10;
//  else Result += ' ';
  Result += GetExtraInfo;
end;

function TListObj.GetInfo(Delimiter: String): String;
begin
  Result := 'Unimplemented getinfo for class "' + Self.ClassName + '"';
end;

function TListObj.GetExtraInfo: String;
begin
  Result := '';
end;

{ TComment }

function TComment.GetInfo(Delimiter: String): String;
begin
  if xmlComment then
  begin
    Result := GlobalIndent + '(*' + #13#10;
    IncIndent;
    Result += IndentString(Text + #13#10);
    DecIndent;
    Result +=  GlobalIndent + '*)' + #13#10
  end
  else Result := IndentString('{ ' + Text + ' }') + #13#10;
end;

procedure TComment.LoadFromXMLCommentNode(const Node: TDOMNode);
begin
  xmlComment := True;
  Text := Trim(Node.TextContent);
end;

{ TField }
function CreateArrayType(aLow, aHigh, aBaseType: String): String;
var aType: TType;
begin
  Result := aBaseType + '_' + aLow + '_' + aHigh;
  aType := GlobalTypes.FindIdentifier('T' + Result);
  if not Assigned(aType) then
  with GlobalTypes.CreateChild do
  begin
    Identifier := 'T' + Result;
    BaseType := 'array[' + aLow + '..' + aHigh + '] of ' + aBaseType;
  end;
end;

procedure TField.LoadFromNode(Node: TDOMNode);
var PointerCount: Integer;
begin
  PointerCount := 0;
  Assert(Node.NodeName = 'param', '');
  Node := Node.FirstChild;
  while Assigned(Node) do
  begin
    case Node.NodeType of
      ELEMENT_NODE:
        case Node.NodeName of
          'name': Identifier := FixReservedWords(Trim(Node.TextContent));
          'type': BaseType := Trim(Node.TextContent);
          else
            raise Exception.Create('Unknown element "' + Node.NodeName + '"')
        end;
      TEXT_NODE:
        case Trim(Node.TextContent) of
          'struct': begin end;
          'const': ConstFlag := True;
          '*': PointerCount := 1;
          '**': PointerCount := 2;
          '* const*':
            begin
              ConstFlag := True;
              PointerCount := 2;
            end;
          '[4]': BaseType := CreateArrayType('0', '3', BaseType); // PointerCount := 1;
          else
            try
              raise Exception.Create('Unknown text "' + Node.TextContent + '"')
            except
            end;
        end;
    end;
    Node := Node.NextSibling;
  end;
  SubType := TranslateTypeToPascal(0, BaseType);
  BaseType := TranslateTypeToPascal(PointerCount, BaseType);
end;

function TField.GetInfo(Delimiter: String): String;
begin
  Result := '';
//  if ConstFlag then Result += 'const ';
  if GlobalUseIndent then Result += GlobalIndent;
  Result += Identifier + ': ' + BaseType + Delimiter;
end;

{ TType }

function TType.GetInfo(Delimiter: String): String;
begin
  Result := GlobalIndent + Identifier + ' = ' + BaseType + Delimiter;
end;

function TType.GetExtraInfo: String;
begin
  Result := '';
  if NeededPointerDepth > 0 then Result += GetPointerDepth(Identifier, NeededPointerDepth);
end;

procedure TType.LoadFromBitmaskNode(Node: TDOMNode);
begin
  Identifier := 'T' + GetChildNodeContents(Node, 'name');
  BaseType := GetAttribute(Node, 'requires');

  if BaseType <> '' then
//    BaseType := 'TSetOf_' + BaseType
    BaseType := 'set of ' + 'T' + BaseType + '_'
  else
    BaseType := 'T' + GetChildNodeContents(Node, 'type');
  AcceptLateComment := True;
end;

procedure TType.LoadFromHandleNode(Node: TDOMNode);
begin
  BaseType := GetChildNodeContents(Node, 'type');
  case BaseType of
    'VK_DEFINE_HANDLE': BaseType := 'TVkHandle';
    'VK_DEFINE_NON_DISPATCHABLE_HANDLE': BaseType := 'TVkNonDespatchableHandle';
    else raise Exception.Create('Unhandled handle :-)');
  end;
  Identifier := 'T' + GetChildNodeContents(Node, 'name');
  CommentInternal := GetAttribute(Node, 'parent');
  if CommentInternal <> '' then CommentInternal := 'parent is ' + CommentInternal;
end;

{ TConstant }

function TConstant.GetInfo(Delimiter: String): String;
begin
  Result := GlobalIndent + Identifier + ' = ' + Value + Delimiter;
  if CommentInternal <> '' then
    Result += SpaceOutPostComment(Length(Result), CommentInternal);
end;


procedure TConstant.LoadFromEnumNode(Node: TDOMNode);
var out_int: Int64;
    out_single: Single;
begin
  Identifier := GetAttribute(Node, 'name');
  Value := Trim(GetAttribute(Node, 'value'));

  if Value[Length(Value)] = 'f' then SetLength(Value, Length(Value) - 1);

  if not (TryStrToInt64(Value, out_int) or TryStrToFloat(Value, out_single)) then
    case Value of
      '(~0U)': Value := '(not 0)';
      '(~0ULL)': Value := '(not 0)';
      '(~0U-1)': Value := '((not 0) - 1)';
      else raise Exception.Create('unknown constant');
    end;
end;

procedure TConstant.LoadFromVendorNode(Node: TDOMNode);
begin
  Identifier := FixReservedWords(GetAttribute(Node, 'name'));
  Value := GetAttribute(Node, 'id');
  Value := StringReplace(Value, '0x', '$', [rfIgnoreCase, rfReplaceAll]);
  CommentInternal := GetAttribute(Node, 'comment');
end;

procedure TConstant.LoadFromTagNode(Node: TDOMNode);
begin
  CommentInternal := GetAttribute(Node, 'contact');
  if CommentInternal <> '' then CommentInternal := 'contact: ' + CommentInternal;

  Identifier := GetAttribute(Node, 'name') + '_tag';
  Value := '''' + GetAttribute(Node, 'author') + '''';
end;

{ TEnum }

procedure TEnum.LoadFromNode(Node: TDOMNode);
var strValue, strBitPos: String;

    procedure FindNextSiblingEnum;
    var Found: Boolean;
    begin
      Found := False;
      while Assigned(Node) and (not Found) do
      begin
        if Node.NodeType = COMMENT_NODE then
        begin
          GlobalComments.CreateChild.Text := Trim(Node.TextContent);
        end
        else
        if Node.NodeName = 'enum' then
        begin
          Exit;
          if not BitmaskFlag then Exit;
          strValue := GetAttribute(Node, 'bitpos');
          if strValue <> '' then Exit;
        end;
        Node := Node.NextSibling;
      end;
    end;
var aConstant: TConstant;
begin
  Identifier := 'T' + GetAttribute(Node, 'name');
  strValue := GetAttribute(Node, 'type');

  if (strValue <> 'enum') and (strValue <> 'bitmask') then
    raise Exception.Create('TEnum.LoadFromNode called with "' + strValue + '"');

  BitmaskFlag := strValue = 'bitmask';

  Node := Node.FirstChild;
  FindNextSiblingEnum;

  while Assigned(Node) do
  begin
    strBitPos := GetAttribute(Node, 'bitpos');
    strValue := GetAttribute(Node, 'value');

    if (strBitPos = '') and (strValue = '') then
      raise Exception.Create('uninitialized enum value');
    if BitmaskFlag and (strValue <> '') then
      aConstant := ExtraConstants.CreateChild
    else
      aConstant := Values.CreateChild;
    with aConstant do
    begin
      Identifier := GetAttribute(Node, 'name');
      CommentInternal := GetAttribute(Node, 'comment');
      if strBitPos <> '' then Value := strBitPos
      else Value := strValue;

      if Pos('0x', Value) <> 0 then
        Value := StringReplace(Value, '0x', '$', [rfIgnoreCase, rfReplaceAll]);

      Node := Node.NextSibling;
      FindNextSiblingEnum;
    end;

  end;
end;

function TEnum.GetInfo(Delimiter: String): String;
var ii: Integer;
    aConstant: TConstant;
    SetValue: UInt64;
    Mask: UInt64;
    SetList, ss: String;
    id2: String;

    function LookupEnum(aValue: String): String;
    var ac: TConstant;
    begin
      for ac in Values do
      if ac.Value = aValue then
      begin
        Result := ac.Identifier;
        Exit;
      end;
      Result := '';
    end;

var NeedsInitialization: Boolean;
begin
  Values.Sort(@EnumSort);

  ss := Identifier;
  if BitmaskFlag then ss += '_';
  Result := GlobalIndent + ss + ' = (' + #13#10;
  IncIndent;
  Result += Values.GetListing(False, ',');
  DecIndent;
  Result += GlobalIndent + ');' + #13#10;
  if BitMaskFlag then
  begin
    id2 := Identifier;
//    Delete(id2, 1, 1);
//    id2 := 'TSetOf_' + id2;
    id2 := 'set of ' + ss;
    Result += GlobalIndent + Identifier + ' = set of ' + ss + ';' + #13#10;
  end;
  if NeededPointerDepth > 0 then Result += GetPointerDepth(Identifier, NeededPointerDepth);


  if ExtraConstants.Count > 0 then
  begin
    Result += GlobalIndent + 'const' + #13#10;
    IncIndent;

{    for aConstant in Values do
    with aConstant do
      FValue := StrToInt(Value); }

    for aConstant in ExtraConstants do
    with aConstant do
    begin
      SetList := '';
      SetValue := StrToInt(Value);
      Mask := $1;

      NeedsInitialization := False;
      for ii := 0 to 63 do
      begin
        if (Mask and SetValue) <> 0 then
        begin
          ss := LookupEnum(IntToStr(ii));
          if ss = '' then
          begin
            NeedsInitialization := True;
            break;
          end;
          SetList := SetList + ss + ', ';
        end;
        Mask := Mask shl 1;
      end;
      if NeedsInitialization then
      begin
        Result += GlobalIndent + 'var' + #13#10;
        IncIndent;
        Result += GlobalIndent + Identifier + ': ' + id2 + ';' + #13#10;
        DecIndent;
//        Result += 'const' + #13#10;
        GlobalInitialization += '  PInteger(@' + Identifier + ')^ := ' + Value + ';' + #13#10;
      end
      else
      begin
        SetLength(SetList, Length(SetList) - 2);
        Result += GlobalIndent + Identifier + ' = [' + SetList + '];' + #13#10;
      end;

    end;
    DecIndent;
//    Result += ExtraConstants.GetListing(True, ';');
    Result += GlobalIndent + 'type' + #13#10;
  end;
end;

constructor TEnum.Create;
begin
  Values := TConstantList.Create(True);
  ExtraConstants := TConstantList.Create(True);
end;

destructor TEnum.Destroy;
begin
  FreeAndNil(Values);
  FreeAndNil(ExtraConstants);
  inherited Destroy;
end;

{ TStruct }

procedure TStruct.GetFields(Node: TDOMNode);
var strName, strBaseType: String;
    nn: TDOMNode;
    ss: String;
    aConstFlag: Boolean;
    PP: Integer;
    ii: Integer;
    ArrayDim: String;
    strMember: String;
    strSubType: String;
begin
  Inc(structcount);
  while Assigned(Node) do
  begin
    if Node.NodeName = 'member' then
    begin
      nn := Node.FirstChild;
      aConstFlag := False;
      ArrayDim := '';
      if nn.NodeType = TEXT_NODE then
      begin
        ss := nn.TextContent;
        ss := Trim(ss);
        if (ss <> 'const') and (ss <> 'struct') then
          raise Exception.Create('Unknown prefix "' + ss + '" in struct');
        aConstFlag := True;
        nn := nn.NextSibling;
      end;

      if nn.NodeType <> ELEMENT_NODE then
        raise Exception.Create('here');
      ss := nn.NodeName;
      if nn.NodeName <> 'type' then
        raise Exception.Create('here2');
      strBaseType := Trim(nn.TextContent);
      nn := nn.NextSibling;

      PP := 0;
      if nn.NodeType = TEXT_NODE then
      begin
        ss := Trim(nn.TextContent);
        case ss of
          '*': PP := 1;
          '**': PP := 2;
          '* const*':
          begin
            PP := 2;
            aConstFlag := True;
          end;
          else
            raise Exception.Create('unknown prefix');
        end;
        nn := nn.NextSibling;
      end;

      if nn.NodeTYpe <> ELEMENT_NODE then
        raise Exception.Create('here3');
      if nn.NodeName <> 'name' then
        raise Exception.Create('here4');
      strName := Trim(nn.TextContent);
      strName := FixReservedWords(strName);

      nn := nn.NextSibling;
      if Assigned(nn) then
      begin
        ss := Trim(nn.TextContent);
        if ss[1] <> '[' then
          raise Exception.Create('here5');
        if ss[Length(ss)] = ']' then
        begin
          ss := Copy(ss, 2, Length(ss) - 2);
          ii := StrToInt(ss);
          ArrayDim := '0..' + IntToStr(ii - 1);
        end
        else
        begin
          nn := nn.NextSibling;
          if nn.NodeName <> 'enum' then
            raise Exception.Create('here6');
          ss := nn.TextContent;
          ArrayDim := '0..(' + ss + ' - 1)';
        end;
      end;

      strSubType := TranslateTypeToPascal(0, strBaseType);
      strBaseType := TranslateTypeToPascal(PP, strBaseType);
      strMember := strName + ': ';
      if ArrayDim <> '' then
        strBaseType := 'array[' + ArrayDim + '] of ' + strBaseType;
      strMember += strBaseType + ';';
      with FieldList.CreateChild do
      begin
        Identifier := strName;
        BaseType := strBaseType;
        SubType := strSubType;
        ConstFlag := aConstFlag;
      end;
    end;
    Node := Node.NextSibling;
  end;
end;

function TStruct.GetInfo(Delimiter: String): String;
var aField: TField;
    ii: Integer;
begin
  Result := '';

  if Assigned(Extension) then
    Result += '{$IFDEF ' + Extension.ProtectDefine + '}' + #13#10;
  Result += GlobalIndent + Identifier + ' = record' + #13#10;
  IncIndent;
  if not UnionFlag then
    Result += FieldList.GetListing(True, ';')
  else
  begin
    ii := 0;
    Result += GlobalIndent + 'case Integer of' + #13#10;
    IncIndent;
    for aField in FieldList do
    begin
      Result += GlobalIndent + IntToStr(ii) + ': (' + aField.GetListing(';') + ');' + #13#10;
      Inc(ii);
    end;
    DecIndent;
  end;
{  case Identifier of
    'TVkExtensionProperties', 'TVkLayerProperties', 'TVkQueueFamilyProperties':
        Result += GlobalIndent + 'class operator = (const a,b: ' + Identifier + '): Boolean;' + #13#10;
  end; }

  DecIndent;
  Result += GlobalIndent + 'end;' + #13#10;

  if NeededPointerDepth > 0 then Result += GetPointerDepth(Identifier, NeededPointerDepth);

  case Identifier of
    'TVkPhysicalDeviceFeatures':
      begin
        Result += GlobalIndent + Identifier + '_enum = (' + #13#10;
        IncIndent;
        for aField in FieldList do
          Result += GlobalIndent + aField.Identifier + ',' + #13#10;
        SetLength(Result, Length(Result) - 3);
        Result += #13#10;

        DecIndent;
        Result += GlobalIndent + ');' + #13#10;
//        Result += GlobalIndent + 'TSetOf_' + Copy(Identifier, 2, Length(Identifier) - 1) + ' = set of ' + Identifier + '_enum;' + #13#10;
      end;
  end;

  if Assigned(Extension) then
    Result += '{$ENDIF ' + Extension.ProtectDefine + '}' + #13#10;
end;

procedure TStruct.LoadFromNode(Node: TDOMNode);
begin
  UnionFlag := Lowercase(GetAttribute(Node, 'category')) = 'union';
  Identifier := 'T' + GetAttribute(Node, 'name');
  GetFields(Node.FirstChild);
end;

constructor TStruct.Create;
begin
  FieldList := TFieldList.Create(True);
end;

destructor TStruct.Destroy;
begin
  FreeAndNil(FieldList);
  inherited Destroy;
end;

{ TFunctionDefinition }

procedure TFunctionDefinition.LoadFromNode(Node: TDOMNode);
var strReturnType: String;
    strFunctionTypeName: String;
    strParameterType: String;
    strParameterName: String;
    ss: String;
    ii: Integer;
    pp: Integer;
    aConstFlag: Boolean;

    procedure FixForConst(var ss: String);
    begin
      ss := Trim(ss);
      aConstFlag := False;
      if Pos('const', ss) = (Length(ss) - Length('const') + 1) then
      begin
        aConstFlag := True;
        SetLength(ss, Length(ss) - Length('const'));
        ss := Trim(ss);
      end;
    end;
begin
  Node := Node.FirstChild;
  Assert(Node.NodeType = TEXT_NODE, '');
  strReturnType := Trim(Node.TextContent);
  ss := 'typedef ';
  Assert(ss = Copy(strReturnType, 1, Length(ss)), '');
  Delete(strReturnType, 1, Length(ss));
  ss := ' (VKAPI_PTR *';
  Assert(ss = Copy(strReturnType, Length(strReturnType) - Length(ss) + 1, Length(ss)), '');
  Delete(strReturnType, Length(strReturnType) - Length(ss) + 1, Length(ss));
  case strReturnType of
    'void': strReturnType := '';
    'void*': strReturnType := 'Pointer';
    'VkBool32': strReturnType := 'TVkBool32';
    else raise Exception.Create('Unhandled return type');
  end;

  Node := Node.NextSibling;
  Assert(Node.NodeType = ELEMENT_NODE, '');
  Assert(Node.NodeName = 'name', '');
  strFunctionTypeName := Trim(Node.TextContent);
  strFunctionTypeName := 'T' + strFunctionTypeName;

  Identifier := strFunctionTypeName;
  ReturnType := strReturnType;

  Node := Node.NextSibling;
  ss := Node.TextContent;
  FixForConst(ss);

  Node := Node.NextSibling;
  while Assigned(Node) do
  with ParameterList.CreateChild do
  begin
    ConstFlag := aConstFlag;

    strParameterType := Node.TextContent;
    Node := Node.NextSibling;
    if not Assigned(Node) then
      raise Exception.Create('error parsing function');
    strParameterName := Node.TextContent;
    ii := 1;
    while (ii < Length(strParameterName)) and (strParameterName[ii] in [' ', '*'])  do Inc(ii);
    ss := Copy(strParameterName, 1, ii - 1);
    Delete(strParameterName, 1, ii - 1);
    pp := 0;
    for ii := 1 to Length(ss) do
      case ss[ii] of
        '*': Inc(pp);
      end;


    strParameterName := Trim(strParameterName);
    FixForConst(strParameterName);
    ii := Length(strParameterName);
    while (ii > 0) and (strParameterName[ii] in [',', ' ', ')', ';', #0]) do
      Dec(ii);
    Delete(strParameterName, ii + 1, Length(strParameterName) - ii);
    strParameterName := FixReservedWords(strParameterName);
    strParameterType := TranslateTypeToPascal(PP, strParameterType);
    Identifier := strParameterName;
    BaseType := strParameterType;

    Node := Node.NextSibling;
  end;
end;

function TFunctionDefinition.GetInfo(Delimiter: String): String;
begin
  Result := GlobalIndent + Identifier + ' = ';
  if ReturnType = '' then Result += 'procedure('
  else Result += 'function(';

  Result += #13#10;

  IncIndent;
  Result += ParameterList.GetListing(False, ';');
  DecIndent;
  Result += GlobalIndent + ')';
  if ReturnType <> '' then Result += ': ' + ReturnType;
  Result += ';' + #13#10;
end;

constructor TFunctionDefinition.Create;
begin
  ParameterList := TFieldList.Create(True);
end;

destructor TFunctionDefinition.Destroy;
begin
  FreeAndNil(ParameterList);
  inherited Destroy;
end;

{ TCreateChildList }

function TCreateChildList.CreateChild(Level: Integer): T;
begin
  Result := T.Create;
  Result.FLevel := Level;
  if Level = -1 then Add(Result)
  else Insert(Level, Result);

  if Result.ClassType = TComment then
  with TComment(TListObj(Result)) do
  begin
    PreviousObject := LastObj;
    if Assigned(LastObj) and LastObj.AcceptLateComment then
    begin
      LastObj.PostComment := TComment(TListObj(Result));
      FUsed := True;
    end;
  end;

  LastObj := Result;
  if Assigned(LastComment) then
  begin
    LastComment.NextObject := Result;
    if not LastComment.FUsed then
    begin
      LastComment.FUsed := True;
      LastObj.PreComment := LastComment;
    end;
    LastComment := nil;
  end;
  if Result.ClassType = TComment then
    LastComment := TComment(TListObj(Result));
end;

function TCreateChildList.GetListing(IncludeLastDelimiter: Boolean; aDelimiter: String; NoCRLF: Boolean): String;
var tt: T;
begin
  Result := '';
  for tt in Self do
  begin
    if IncludeLastDelimiter or (tt <> Last) then Result += tt.GetListing(aDelimiter, NoCRLF)
    else Result += tt.GetListing('', NoCRLF);
  end;
end;

function TCreateChildList.FindIdentifier(aIdentifier: String): T;
begin
  for Result in Self do
  begin
    if aIdentifier = Result.Identifier then Exit;
  end;
  Result := nil;
end;

function TCreateChildList.FindIdentifierIndex(aIdentifier: String): Integer;
var aObj: T;
begin
  Result := -1;
  aObj := FindIdentifier(aIdentifier);
  if not Assigned(aObj) then Exit;
  Result := IndexOf(aObj);
end;

procedure TCreateChildList.MoveIdentifierBefore(aIdentifier1, aIdentifier2: String);
var Index1, Index2: Integer;
begin
  System.Delete(aIdentifier1, 1, 1);
  System.Delete(aIdentifier2, 1, 1);
  aIdentifier1 := 'T' + aIdentifier1;
  aIdentifier2 := 'T' + aIdentifier2;

  Index1 := GlobalStructs.FindIdentifierIndex(aIdentifier1);
  Index2 := GlobalStructs.FindIdentifierIndex(aIdentifier2);

  if (Index1 <> -1) and (Index2 <> -1) then
  Move(Index1, Index2);
end;

procedure SaveVulkanIncludeFiles(SourceXMLFilename: String);
  procedure SaveStringToFile(ss: String; FileName: String);
  begin
    with TFileStream.Create(FileName, fmCreate or fmShareDenyNone) do
    try
      Write(ss[1], Length(ss));
    finally
      Free;
    end;
  end;
var Doc: TXMLDocument;
  VHIF: TVulkanHeaderIncludeFiles;
begin
  try
    ReadXMLFile(Doc, SourceXMLFilename);
    GetPascalHeader(Doc, VHIF);
  finally
    FreeAndNil(Doc);
  end;
  SaveStringToFile(VHIF.ConstantsAndTypes, 'vulkan_constants_and_types.inc');
  SaveStringToFile(VHIF.FunctionVariables, 'vulkan_functionvariables.inc');
  SaveStringToFile(VHIF.DBGFunctionDeclarations, 'vulkan_dbgclass_type.inc');
  SaveStringToFile(VHIF.FunctionAssignments, 'vulkan_functionassignments.inc');
  SaveStringToFile(VHIF.DBGFunctionImplementations, 'vulkan_dbgclass_implementation.inc');
  SaveStringToFile(VHIF.GlobalInitialization, 'vulkan_headerinitialization.inc');
end;

procedure HandleChildren(Node: TDOMNode);
begin
  Node := Node.FirstChild;
  while Node <> Nil do
  begin
    HandleNode(Node);
    Node := Node.NextSibling;
  end;
end;

procedure HandleTypeNode(Node: TDOMNode);
var strCategory: String;
    strRequires, strName, strType, strBaseType: String;
begin
  strCategory := GetAttribute(Node, 'category');
  case Lowercase(strCategory) of
    'basetype':
      begin
        strName := 'T' + GetChildNodeContents(Node, 'name');
        strBaseType := GetChildNodeContents(Node, 'type');
        if strBaseType = 'HINSTANCE' then
        begin
          strBaseType := strBaseType;
        end;
        AddGlobalType(strName, strBaseType);
      end;
    '':
      begin
        strRequires := GetAttribute(Node, 'requires');
        strName := GetAttribute(Node, 'name');
        if (strRequires = 'vk_platform') or (strName = 'int') or (strName = 'DWORD') or (strName = 'LPCWSTR') then
        begin
          case strName of
            'void': begin end;
            'char': begin end;
            'DWORD': begin end; //AddGlobalType('dword', 'DWord', True);
            'LPCWSTR': begin end; //AddGlobalType('lpcwstr', 'LPCWSTR', True);
            'int': AddGlobalType('int', 'PtrInt', True);
            'float': AddGlobalType('float', 'Single', True);
            'uint8_t': AddGlobalType('uint8_t', 'Byte', True);
            'uint32_t': AddGlobalType('uint32_t', 'Cardinal', True);
            'uint64_t': AddGlobalType('uint64_t', '{$IFDEF DEFINE_UINT64_EQU_INT64} Int64{$ELSE} UInt64{$ENDIF}', True);
            'int32_t': AddGlobalType('int32_t', 'Longint', True);
            'size_t': AddGlobalType('size_t', 'UintPtr', True);
            else raise Exception.Create('unhandled base type');
          end;
          if strType <> 'void' then BaseTypes.Add(strName);
        end;
      end;
    'funcpointer': GlobalFunctionDefinitions.CreateChild.LoadFromNode(Node);
    'enum': begin end;
    'define':
      begin
        strName := GetAttribute(Node, 'name');
        if strName = '' then
          strName := GetChildNodeContents(Node, 'name');
        case strName of
          'VK_DEFINE_HANDLE':
          with GlobalTypes.CreateChild do
          begin
            Identifier := 'TVkHandle';
            BaseType := 'PtrUInt';
          end;
          'VK_DEFINE_NON_DISPATCHABLE_HANDLE':
          with GlobalTypes.CreateChild do
          begin
            Identifier := 'TVkNonDespatchableHandle';
            BaseType := '{$IFNDEF DEFINE_UINT64_EQU_INT64} UInt64{$ELSE} Int64{$ENDIF}';
          end;
        end;
      end;
    'include':
      begin

        //Add(strCategory + ' -> ' + GetChildNodeContents(Node, 'name'), 1);
      end;
    'bitmask': GlobalTypes.CreateChild.LoadFromBitmaskNode(Node);
    'handle': GlobalTypes.CreateChild.LoadFromHandleNode(Node);
    'struct', 'union': GlobalStructs.CreateChild.LoadFromNode(Node);
    else raise Exception.Create('Unhandled type category: ' + strCategory);
  end;
end;

function EnumSort(const Item1, Item2: TConstant): Integer;
var i1, i2: Int64;
begin
  Result := 0;
  try
    i1 := StrToInt(Item1.Value);
    i2 := StrToInt(Item2.Value);
    Result := i1 - i2;
  except
  end;
end;

procedure HandleNode(Node: TDOMNode);
var strName: String;
begin
  case Node.NodeType of
    COMMENT_NODE:
    begin
      with GlobalComments.CreateChild do
        Text := Trim(Node.TextContent);
    end;
    ELEMENT_NODE:
      case LowerCase(Node.NodeName) of
        'vendorids', 'tags', 'types', 'extensions', 'commands': HandleChildren(Node);

        'extension': GlobalExtensions.CreateChild.LoadFromNode(Node);
        'comment': GlobalComments.CreateChild.LoadFromXMLCommentNode(Node);
        'vendorid': GlobalConstants.CreateChild.LoadFromVendorNode(Node);
        'tag': GlobalConstants.CreateChild.LoadFromTagNode(Node);
        'enums':
          begin
            strName := GetAttribute(Node, 'name');
            if strName = 'API Constants' then // special case
              CreateEnumConstants(Node)
            else
              GlobalEnums.CreateChild.LoadFromNode(Node);
          end;
        'command': GlobalCommands.CreateChild.LoadFromNode(Node);
        'type': HandleTypeNode(Node);
      end;
  end;
end;


end.

