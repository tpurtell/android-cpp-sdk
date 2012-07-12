import os
import sys

def IsJavaFile(fileName):
    if os.path.splitext(fileName)[1][1:] == 'java':
            return True
    return False

def IsJavaFileInside(FilesList):
    for item in FilesList:
        if IsJavaFile(item):
            return True
    return False

def GetDirListWithJavaFiles(initialDirectory):
    result = []
    for root, dirs, files in os.walk(initialDirectory):
        if IsJavaFileInside(files):
            result.append(root[len(initialDirectory) + 1:])
    return result

def CutPath(path):
    result = []
    while not len(path) == 0:
        (head, tail) = os.path.split(path)
        result.append(tail)
        path = head
    result.reverse()
    return result

def RecreateDirectorySrtuct(pathesList, dirName):
    for folder in pathesList:
        root = dirName
        for dirToCreate in CutPath(folder):
            root = os.path.join(root, dirToCreate)
            if not os.path.exists(root):
                try:
                    os.mkdir(root)
                except:
                    print "failed to create : " + str(root)

def ReadEntireFile(path):
    f = open(path, 'r')
    result = f.readlines();
    f.close()
    return result
#-----------------------------------------------------------------------
def GetIncludes(fileContent):
    result = []
    for line in fileContent:
        if line.startswith("import "):
            result.append(line.split(' ')[1][:-2])
    return result

def TranslateIncludes(includes):
    result = []
    for include in includes:
        temp = "#include <" + include.replace(".", "/") + ".hpp>\n"
        result.append(temp)
    return result

def PutIncludes(fileObject, includes):
    for include in includes:
        fileObject.write(include)
#-----------------------------------------------------------------------
class NameSpaceWrapper:
    def __init__(self, nameSpacesList, fileObject):
        self.fileObject = fileObject
        self.bracketsCount = len(nameSpacesList) + 1
        fileObject.write("\n\nnamespace j2cpp {")
        for namespace in nameSpacesList:
            fileObject.write("namespace " + namespace + " {")
        fileObject.write("\n")
        
    def __del__(self):
        for x in xrange(0, self.bracketsCount):
            self.fileObject.write("}")
        self.fileObject.close()
        
def GetNamespaces(fileContent):
    for line in fileContent:
        if line.startswith("package "):
            namespaces = line.split(' ')[1][:-2]
            return namespaces.split('.')
    
#-----------------------------------------------------------------------        
def TranslateFile(inputFilePath, outputFilePath):
    fileContent = ReadEntireFile(inputFilePath)
    outputFile = open(outputFilePath, "w+")

    #proceed with includes
    includes = GetIncludes(fileContent)
    PutIncludes(outputFile, TranslateIncludes(includes))
    
    #proceed with namespaces
    nameSpaces = GetNamespaces(fileContent)
    wrapper = NameSpaceWrapper(nameSpaces, outputFile)
    classTree = BuildClassTree(fileContent)

def TranslateFolder(dirToTranslateFrom, dirToTranslateTo):
    
    #prepare folder struct
    dirstToCteate = GetDirListWithJavaFiles(dirToTranslateFrom)
    RecreateDirectorySrtuct(dirstToCteate, dirToTranslateTo)
    
    #translate files
    for root, dirs, files in os.walk(dirToTranslateFrom):
        for fileItem in files:
            if IsJavaFile(fileItem):
                fileToTranslateFrom = os.path.join(root, fileItem)
                fileToTranslateTo = fileToTranslateFrom.replace(dirToTranslateFrom, dirToTranslateTo).replace('.java', '.hpp')
                TranslateFile(fileToTranslateFrom, fileToTranslateTo)

def Help():
    print "To start the script pleace specify the:"
    print "1. Path to directory with android sources"
    print "2. Path to output directory"

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

def main():
    args = sys.argv
#    print BuildClassTree(ReadEntireFile("D:\\2commit\\New folder\\android\\app\\ActivityGroup.java"))
#    if len(args) < 3:
#        Help()
#        return
#    TranslateFolder(args[1], args[2])
    TranslateFolder("D:\\2commit\\New folder", "D:/test")


if __name__ == "__main__":
    main()
