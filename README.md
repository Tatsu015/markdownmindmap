# MarkdownMindMap
A mindmap drawing tool by text format.

## Description
MarkdownMindMap is a tool for drawing mindmap diagram based on a simple syntax.

## DEMO
![](https://user-images.githubusercontent.com/97239922/149974526-6f7cb960-22c7-42e9-856c-baf6e444a8a6.gif)

## Features
- Almost no cost to learn how to use.
- As you can not decorate, you can concentrate on thinking.
- You can control version easily because text format.

## Requirement
- C++
- Qt 5.9.5+

## Usage
1. Edit left hand side text edit area based on syntax rule.
1. Automaticaly mind map diagram generete in right hand side graphics area.

### syntax rules
* If you add an indent to the text, this line of text will be child node of the upper nearest side line of one less indent.

## Installation
Paste the following commands at a Terminal prompt.

    $ git clone https://github.com/Tatsu015/markdownmindmap.git
    cd markdownmindmap
    ./build.sh

When use this command, you need to add qmake path to the environment path.

## Anything Else
- sample project file exist in sample directory.

## Author
Tatsu015

## License
[MIT](http://b4b4r07.mit-license.org)
