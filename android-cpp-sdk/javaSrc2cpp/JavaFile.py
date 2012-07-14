def GetClassNameFromLine(line):
    words = line.split(' ')
    for word in words:
        if word == "class":
            index = words.index(word) + 1
            while index < len(words) and words[index] == ' ':
                index += 1
            return words[index]
                
def GetClassLines(fileContent, startIndex):
    index = startIndex
    bracketBalance = fileContent[startIndex].count('{') - fileContent[startIndex].count('}')
    fileContentSize = len(fileContent)
    index += 1
    while (index < fileContentSize) and (bracketBalance > 0):
        bracketBalance += fileContent[index].count('{') - fileContent[index].count('}')
        index += 1
    return fileContent[startIndex:index]

class JavaClass:
    def __init__(self, name):
        self.name = name
        self.nestedClasses = []
        self.methods = []
        self.constructors = []
        self.inheritedFrom = []

    def __str__(self):
        return str((self.name,
                self.nestedClasses,
                self.methods,
                self.constructors,
                self.inheritedFrom))
    
    def __repr__(self):
        return JavaClass.__str__(self)
    
    def WriteClassSubtreeInFile(self, fileToWrite):
        fileToWrite.write("class " + self.name + " {" )
        for nestedClass in self.nestedClasses:
            nestedClass.WriteClassSubtreeInFile(fileToWrite)
        fileToWrite.write("};")
    
    def SetNestedClasses(self, nestedClasses):
        self.nestedClasses += nestedClasses

def BuildClassTree(fileContent):
    fileContentLineCount = len(fileContent)
    tree = []
    index = 0
    while index < fileContentLineCount:
        if "class " in fileContent[index]:
            className = GetClassNameFromLine(fileContent[index])
            javaClass = JavaClass(className)
            classLines = GetClassLines(fileContent, index)
            subTree = BuildClassTree(classLines[1:-1])
            javaClass.SetNestedClasses(subTree)
            tree.append(javaClass)
            index += len(classLines) - 1
        index += 1
    return tree
