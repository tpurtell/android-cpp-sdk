import os

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

def RemoveMultilineComments(fileContent):
    currentIndex = 0
    result = []
    maxIndex = len(fileContent)
    while currentIndex < maxIndex:
        if "/*" in fileContent[currentIndex]:
            index = fileContent[currentIndex].index('/*')
            result.append(fileContent[currentIndex][:index])
            while (currentIndex < maxIndex) and (not '*/' in fileContent[currentIndex]):
                currentIndex += 1
            if currentIndex < maxIndex:
                index = fileContent[currentIndex].index('*/')
                result.append(fileContent[currentIndex][index + 2:])
        else:
            result.append(fileContent[currentIndex])
        currentIndex += 1
    return result
        

def RemoveOneLineComments(fileContent):
    result = []
    for line in fileContent:
        if '//' in line:
            index = line.index('//')
            result.append(line[:index])
        else:
            result.append(line)
    return result
