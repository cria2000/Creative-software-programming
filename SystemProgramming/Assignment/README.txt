				<Assignment.py>
					-2019 시스템프로그래밍 과제
						    학과 : 컴퓨터소프트웨어학부
						    학번 : 2018008722
						    이름 : 유수영

RE는 command line으로 받은 찾고자 하는 단어를 저장한다.
Assignment.py파일은 어디에든 저장되어 있을 수 있고, 
다만 실행 시 파일의 경로를 잘 지정해주기만 하면 잘 실행이 된다.  

getListOfFile(filename)
: 이 함수는 file의 내용을 한줄씩 읽어주는 함수이다.  
fileName이 파일의 이름이고, 이를 parameter로 넘겨주어 file을 함수내에서 찾아,
읽기모드로 열어주고 lines에 하나씩 추가해준다. 

getLineCount(filename)
: 이 함수는 해당 file의 내용의 줄 수를 찾기 위한 함수이다. 
filename이 파일의 이름이고, 이를 parameter로 넘겨주어 file을 함수내에서 찾아,
읽기모드로 열어주고 linecount라는 변수를 통해 file을 한 줄씩 읽을 때마다
linecount의 값을 하나씩 증가시켜준 뒤, 나중에 linecount를 return한다. 

\<luna\>처리 방법 
: python에서 사용되는 \<,\>에 대응되는 regular expression을 사용하지 않고,
\<과 \>에 해당하는 경우들을 하나씩 전부 if문으로 처리해준다.
예를 들어, 
\<luna라면, luna라는 문자열을 단어의 처음에 있어야하는 것이다.
이런 경우에는
1. luna로 시작하는 경우
2. /luna가 있는 경우(하위 디렉토리가 luna로 시작하는 경우)
3. .luna가 있는 경우(확장자가 luna로 시작하는 경우)
이런 식으로 if문을 통해 하나씩 처리해주었다. 


처음에는 사용자에게 입력을 받는 것이 아니라 command line의 값으로 받기 때문에 
command line으로 받았을 경우와 사용자 input으로 받았을 경우를 나누어 코드를 짠다. 

for문으로 시작하는 것이 command line으로 찾고자 하는 단어를 받았을 경우이다.
if문으로 \<이 포함되는 경우, \>가 포함되는 경우, 두개다 포함되는 경우, 전부 다 아닌 경우로 
나눈다. 
\<이나 \>가 포함되는 경우는 각각의 경우를 if문으로 구분하여 해당되는 경우는 file1에 적어준다.
(우선 모든 file의 이름을 file2에 담아준 뒤, 
file2의 내용 중 찾고자 하는 regualr expression이 맞는 것이 있으면 그 줄을 file1에 적어준다.)
그 뒤 file1의 내용을 10줄 이하로(혹은 linecount-파일의 개수-) 출력해주어
사용자가 그 중 다시 선택할 수 있도록 해준다. 
만약, linecount가 0이나 1이라면 그냥 break를 해주고, 아래의 코드에서 따로 처리해준다. 
(while True 안에서)

\<나 \>가 포함되는 경우는 위와 동일하며, 그렇지 않은 경우는
file1에 grep 명령어를 사용하여 찾고자 하는 regular expression에 해당하는 이름을 가진 
파일들의 이름을 적어준 뒤 ,
file1의 내용을 10줄 이하로 출력해주어 사용자가 그 중 재선택을 할 수 있도록 해준다. 

이렇게 되면, command line으로 받은 regular expression은 처리된 것이다. 
command line에으로 받은 regular expression에 부합하는 파일들의 이름이 file1에 적혀있는 상태이다.
그 상태에서 while문으로 그 뒤 처리를 실행한다. 

file1에 적혀있는 내용의 줄 수(command line으로 받은 regular expression에 부합하는 파일이름의 개수)
로 구분하여 처리한다.

만약 linecount가 0이라면 부합하는 file이 없는 것이므로, 
file이 없다는 안내문을 출력해주고, 위에서 사용되었던 임시 파일인 file1과 file2가 존재한다면 삭제해준 뒤,
그대로 종료한다. 

만약 linecount가 1이라면 부합하는 file이 하나 있는 것이므로, 
그 파일을 vi로 열리도록 해준다. 
그리고 위와 같이 file1과 file2를 삭제해주고 종료한다. 

위의 if문에서 걸러지지 않는다면 입력을 요구하는 안내문을 출력한 뒤, 사용자에게 입력을 받는다.

만약 입력이 숫자라면, 
listOfFiles(regular expression에 부합하는 파일의 이름을 list로 만든 것)에서 해당하는 파일을 꺼내와
vi로 파일을 열고 종료한다. 

입력이 문자라면, (또 다른 regular expression이라면)
RE변수의 값을 사용자가 입력한 값으로 바꿔주고,
처음 command line에서 처리해줬던 것처럼 if문으로 \<, \>가 포함된 경우와 아닌 경우로 나누어준다.
위와 다른 점이 있다면, 이미 위에서 한 번 선택되어 
file1(command line으로 받은 regular expression에 맞는 파일들의 이름을 적어놓은 file)에 적혀있는
것들 중에서 다시 고르는 것이므로, 그 파일의 내용을 getListOfFile 함수를 통해 File이라는 변수에 저장하고,
그것을 읽어가며 사용자가 다시 입력한 regular expression에 맞는지를 확인하고, 맞다면 file1에 재저장해준다.
(재저장 전, file1의 내용은 전부 지워준다.)

그리고 위에서 했던 것과 똑같이 10줄 이하로 file1의 내용을 출력해준다.(linecount가 0이 아닌 경우에만 출력)

\<나 \>가 포함되지 않는 경우는 grep을 통해 문자열을 검색하며 적합하는 파일들을 찾는다. 

*현재 디렉토리에 있는 파일들만 검색되도록 된 코드이다. 이 문제 제외하고는 예시들에 대해서 원활히 돌아가도록 하였다. 
