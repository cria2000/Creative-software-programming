import os
import random
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression


def getFileList(path) :
    if os.path.exists(path) : 
        fileList = os.listdir(path)
        return fileList
    else :
        return False

def getFileArr(benignFileList, malwareFileList, benignPath, malwarePath) :
    fileArray = []
    for file in benignFileList :
        benignFile = benignPath + "/" + file
        f = open(benignFile, mode = 'rt')
        temp = ''
        line = f.readline()
        while line != '' :
            line = line.rstrip('\n')
            temp = temp + line + ' '
            line= f.readline()
        fileArray.append(temp)
    f.close()
        
    for file in malwareFileList :
        malwareFile = malwarePath + "/" + file
        f = open(malwareFile, mode = 'rt')
        temp = ''
        line = f.readline()
        while line != '' :
            line = line.rstrip('\n')
            temp = temp + line + ' '
            line= f.readline()
        fileArray.append(temp)
        
    f.close()
    return fileArray

def getFileArrOnly(fileList, path) :
    fileArray = []    
    for file in fileList :
        filePath = path + "/" + file
        f = open(filePath, mode = 'rt')
        temp = ''
        line = f.readline()
        while line != '' :
            line = line.rstrip('\n')
            temp = temp + line + ' '
            line= f.readline()
        fileArray.append(temp)
    return fileArray

def doTrainTestSplit(fileList) :
    fileTrain, fileTest = train_test_split(fileList)
    return fileTrain, fileTest
    
def doLogisticRegression(Tfidf, pred, tfidf) :
    label = []    
    for i in range (0,int(Tfidf.shape[0] / 2)) :
        label.append("benign")
    for i in range (0,int(Tfidf.shape[0] / 2)) :
        label.append("malware")       
    model = LogisticRegression()
    model.fit(Tfidf, label)
    predictTfidf = tfidf.transform(pred)
    return model.predict(predictTfidf)

def makeRealList(TBFL, TMFL) :
    real = []
    for i in range (0, len(TBFL)) :
        real.append("benign")
    for i in range (0, len(TMFL)) :
        real.append("malware")
    return real      

def calculateAccuracy(real, predict) :
    matchNum = 0
    benignMalware = 0
    malwareBenign = 0
    benign = 0
    malware = 0
    for i in range (0, len(real)) :
        if real[i] == "benign" :
            benign = benign + 1
        elif real[i] == "malware" :
            malware = malware + 1
            
        if real[i] == predict[i] :
            matchNum = matchNum + 1
        elif real[i] == "benign" and predict[i] == "malware" :
            benignMalware = benignMalware + 1
        elif real[i] == "malware" and predict[i] == "benign" :
            malwareBenign = malwareBenign + 1
    return matchNum / len(real), benign, malware, benignMalware, malwareBenign


def main() :
    
    tfidf= TfidfVectorizer()   

    print("Please enter the path where benign opcode is located and the path where malware opcode is located to training")

    benignPath = input("Benign opcode's path : ")
    malwarePath = input("Malware opcode's path : ")
    benignFileList = getFileList(benignPath)
    malwareFileList = getFileList(malwarePath)
    
    if benignFileList == False or malwareFileList == False :
        print("The path you entered does not exist")
        return

    print("Plese enter the number of files to use within the each folder")
    number= input()
    if int(number) > min(len(benignFileList), len(malwareFileList)) :
        print("Too many numbers")
        return
    
    print("......TRAINING......\n")
    
    benignFileList = random.sample(benignFileList, int(number))
    malwareFileList = random.sample(malwareFileList, int(number))
    benignFileTrain, benignFileTest = doTrainTestSplit(benignFileList)
    malwareFileTrain, malwareFileTest = doTrainTestSplit(malwareFileList)

    FL = getFileArr(benignFileTrain, malwareFileTrain,
                    benignPath,
                    malwarePath)
 
    Tfidf = tfidf.fit_transform(FL)

    print("......TESTING......\n")
    
    TBFL = getFileArrOnly(benignFileTest, benignPath)
    TMFL = getFileArrOnly(malwareFileTest, malwarePath)
    
    TFL = TBFL + TMFL
    real = makeRealList(TBFL, TMFL)
    predictAc = doLogisticRegression(Tfidf, TFL, tfidf)
    Accuracy, benign, malware, benignMalware, malwareBenign = calculateAccuracy(real, predictAc)

    print("A total of", len(benignFileTest) + len(malwareFileTest), "test codes were tested")
    print("This model's accuracy is", Accuracy * 100, "%")
    print(benignMalware, "out of", benign, "benign codes were wrongly classified as malware")
    print(malwareBenign, "out of", malware, "malware codes were wrongly classified as benign\n")
    print("You can choose one of these,\n1. Enter the sequence to check directly")
    print("2. Enter the path of the file that contains the sequence")

    answer = input("Please enter the number\n")
    
    if answer == "1" :
        print("Please enter the sequence that you want to classify")
        seq = input()
        predictSeq = doLogisticRegression(Tfidf, [seq], tfidf)
        if predictSeq[0] == "benign" :
            print("This sequence is benign code")
        elif predictSeq[0] == "malware" :
            print("This sequence is malware code")
            
    elif answer == "2" :
        print("Please enter the file's name and the path that contains the sequence to classify")
        fileName = input("file's name : ")
        path = input("file's path : ")
        if os.path.exists(path) and os.path.isfile(path + "/" + fileName) : 
            PFL = getFileArrOnly([fileName], path)
            predictPath = doLogisticRegression(Tfidf, PFL, tfidf)
            if predictPath[0] == "benign" :
                print("This sequence is benign code")
            elif predictPath[0] == "malware" :
                print("This sequence is malware code")
                
        else :
            print("The path you entered does not exist or there is no file you entered in the path")
            return  
        

        
    
if __name__ == "__main__":
    main()
