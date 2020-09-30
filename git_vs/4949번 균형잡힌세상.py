while True:
    s=input()
    if s[0]=='.':
        break
    stack=[]
    for i in s:
        if i=='(' or i=='[':
            stack.append(i)
        if i==')':
            if stack==[]:
                stack.append(i)
            elif stack!=[] and stack[-1]=='(':
                stack.pop()
            elif stack[-1]!='(':
                stack.append(i)

        elif i==']':
            if stack==[]:
                stack.append(i)
            elif stack!=[] and stack[-1]=='[':
                stack.pop()
            elif stack[-1]!='[':
                stack.append(i)
                
    if stack==[]:
        print("yes")
    else:
        print("no")