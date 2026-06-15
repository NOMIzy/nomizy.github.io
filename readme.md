# 本地测试
- mkdocs new . //如果项目已建立就不用
- mkdocs build
- mkdocs serve //注意不要端口冲突

# 推送至github
- mkdocs build
- git add .
- git commit //i-修改 esc-退出修改 :w - 保存 :q - 退出 （注意英文符号）
- mkdocs gh-deploy --force //报错不要紧
- git push wikissh Head:origin 或 git push wiki Head:origin
远程仓库使用origin分支来做page，有第四条命令会让这次推送只推site部分