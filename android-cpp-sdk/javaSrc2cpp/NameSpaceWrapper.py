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
       
def GetNamespaces(fileContent, filePath):
    for line in fileContent:
        if line.startswith("package "):
            namespaces = line.split(' ')[1][:-2]
            return namespaces.split('.')
