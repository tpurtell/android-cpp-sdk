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
