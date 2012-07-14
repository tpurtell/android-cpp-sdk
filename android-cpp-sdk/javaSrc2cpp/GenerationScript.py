import os
import sys
import FileUtils
import NameSpaceWrapper
import JavaFile
import Includes
        
def TranslateFile(inputFilePath, outputFilePath):
    fileContent = FileUtils.ReadEntireFile(inputFilePath)
    outputFile = open(outputFilePath, "w+")

    #remove comments
    fileContent = FileUtils.RemoveMultilineComments(fileContent)
    fileContent = FileUtils.RemoveOneLineComments(fileContent)

    #proceed with includes
    includes = Includes.GetIncludes(fileContent)
    Includes.PutIncludes(outputFile, Includes.TranslateIncludes(includes))
    
    #proceed with namespaces
    nameSpaces = NameSpaceWrapper.GetNamespaces(fileContent, inputFilePath)
    wrapper = NameSpaceWrapper.NameSpaceWrapper(nameSpaces, outputFile)

    #writing classes into a file
    classTree = JavaFile.BuildClassTree(fileContent)
    for classItem in classTree:
        classItem.WriteClassSubtreeInFile(outputFile)

def TranslateFolder(dirToTranslateFrom, dirToTranslateTo):
    
    #prepare folder struct
    dirstToCteate = FileUtils.GetDirListWithJavaFiles(dirToTranslateFrom)
    FileUtils.RecreateDirectorySrtuct(dirstToCteate, dirToTranslateTo)
    
    #translate files
    for root, dirs, files in os.walk(dirToTranslateFrom):
        for fileItem in files:
            if FileUtils.IsJavaFile(fileItem):
                fileToTranslateFrom = os.path.join(root, fileItem)
                fileToTranslateTo = fileToTranslateFrom.replace(dirToTranslateFrom, dirToTranslateTo).replace('.java', '.hpp')
                TranslateFile(fileToTranslateFrom, fileToTranslateTo)

def Help():
    print "To start the script pleace specify the:"
    print "1. Path to directory with android sources"
    print "2. Path to output directory"


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
