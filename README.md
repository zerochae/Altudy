# Altudy

## MEMBER

<a href="https://github.com/zerochae/Altudy/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=zerochae/Altudy&max=8" />
</a>

## Languages
|<img src="https://img.shields.io/badge/Java-007396?style=for-the-badge&logo=Java&logoColor=FFFFFF"/>|<img src="https://img.shields.io/badge/JavaScript-ffb13b?style=for-the-badge&logo=Javascript&logoColor=FFFFFF"/>|<img src="https://img.shields.io/badge/Go-00ADD8?style=for-the-badge&logo=Go&logoColor=FFFFFF"/>|<img src="https://img.shields.io/badge/SQL-F80000?style=for-the-badge&logo=Oracle&logoColor=FFFFFF"/>
|:---:|:---:|:---:|:---:|
|Juwon-Yun <br/> Ahndaegeun <br/> TaeheeLim <br/> show5116|zerochae|Juwon-Yun|leejunseok95|

## How to Upload

```
Follow the logic after fork & clone
```

```js
const createNewFoler = ( BOJ || Programmers ) => {
  const newFolder;
  if(BOJ) newFolder = BOJ/testNo_testName;
  else if(Programmers) newFolder = Programmers/testName;
  
  return newFolder;
} 

const createNewFile = (myName,language) => {
  const newFile = `${myName.language}`;
  
  return newFile;
}

const solve = (file) => {
  const solveFile = file + solution;
  
  return solveFile;
}

const upLoad = (testFolder) => {
  if ( !testFolder ) createNewFoler( BOJ || Programmers );
  const myFile = createNewFile(myName,language);
  const solveFile = solve(myFile);
  
  return git.commit(solveFile).push().pullRequest();
}
```

## Promise

- One Day One Solve

## Role

<details>
<summary> Pull Request </summary>

- remote는 포크된 자신의 레포지토리 주소 입니다.
- branch는 master 하나만 유지합니다.
- Pull requests 메뉴의 new pull request 버튼을 눌러 커밋 내용을 확인합니다.
- PR을 보내고 본인이 Merge 합니다.
</details>

<details>
<summary> Commit Message </summary>
  
- 커밋 메시지의 통일성을 지킵니다.
- 새로운 파일 업로드 시 "Add: 문제이름"
- 기존 파일 수정 시 "Modify: 문제이름"
- 기존 파일 삭제 시 "Remove: 문제이름"
  
</details>
