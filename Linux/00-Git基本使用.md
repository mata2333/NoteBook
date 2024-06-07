# 版本控制

## 提交到git仓库

```bash
git add *
git commit -m "修改的文件内容"
```

## 查看提交记录

查看提交的日志记录

```bash
git log
```

加上--pretty=oneline可以更加详细地查看

```bash
git log --pretty=oneline
git reflog # 查看每一步的操作
```

## 版本回退

使用git reset可以回退版本

```bash
git reset --hard HEAD^  # 回退到上一个版本
git reset --hard HEAD^^ # 回退到上上个版本
git reset --hard HEAD~100 # 回退到上100个版本
git reset --hard 版本号 # 回退到指定版本号的版本
```

## 撤销修改

修改后可以撤销，使用如下指令撤销回修改前的状态

```bash
git checkout -- file
```

