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

## 删除文件

在工作区删除文件后，无法直接commit，需要先使用git rm指令删除文件才可以commit

```bash
rm -rf test.txt
git add *
git commit -m "删除了test文件" # git显示无变化，文件没有被删除
git rm test.txt
git commit -m "删除了test文件" # 这时可以删除成功
```

## 本地库远程连接github

1、**生成SSH密钥对**（如果还没有生成）：

```
bash
复制代码
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

按提示操作，生成密钥对后，默认位置在`~/.ssh/id_rsa`和`~/.ssh/id_rsa.pub`。

2、**将公钥添加到GitHub**：

- 打开`~/.ssh/id_rsa.pub`，复制其中的内容。
- 登录到你的GitHub账号，进入**Settings** -> **SSH and GPG keys** -> **New SSH key**，然后粘贴你的公钥并保存。

3、**启动SSH代理并添加密钥**：

```
bash复制代码eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
```
