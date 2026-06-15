
//顺时针螺旋填充矩阵
//定义上下左右边界，逐步缩小边界的做法
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int nullptr_flag=0;
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i){
                matrix[u][i]=head->val; //向右移动直到最右
                if(head->next==nullptr) {
                    nullptr_flag=1;
                    break;
                } 
                head=head->next;
            } 
            if(++ u > d || nullptr_flag) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            

            for(int i = u; i <= d; ++i){
                matrix[i][r]=head->val; //向下
                if(head->next==nullptr) {
                    nullptr_flag=1;
                    break;
                } 
                head=head->next;
            } 
            if(-- r < l || nullptr_flag) break; //重新设定右边界
           

            for(int i = r; i >= l; --i){
                matrix[d][i]=head->val;
                if(head->next==nullptr) {
                    nullptr_flag=1;
                    break;
                }
                head=head->next;
            }//向左
            if(-- d < u || nullptr_flag)  break; //重新设定下边界
            

            for(int i = d; i >= u; --i){
                matrix[i][l]=head->val;
                if(head->next==nullptr) {
                    nullptr_flag=1;
                    break;
                }
                head=head->next;
            } 
            if(++ l > r || nullptr_flag) break; //重新设定左边界
            
        }
        return matrix;
        
}

// 根据方向走迷宫的做法
// 四个方向，按右、下、左、上顺序记录（因为螺旋也是按这个顺序转的）
short dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        // 初始化答案矩阵，并将所有位置设为 -1
        vector<vector<int>> ans(m,vector<int>(n,-1));
        // (i, j) 是当前矩阵中的坐标，D 是当前的方向
        int i = 0, j = 0, D = 0;
        while (true) {
            // 填写当前位置
            ans[i][j] = head->val;
            head = head->next;
            // 已经没有下一个位置要填了，退出
            if (head == nullptr) break;
            // 算出下一个位置的坐标
            while (true) {
                // 试着往当前方向走一步
                int ii = i + dir[D][0], jj = j + dir[D][1];
                // 会走出矩阵或走到已有数字的格子中，换一个方向
                if (ii < 0 || jj < 0 || ii >= n || jj >= m || ans[ii][jj] >= 0) D = (D + 1) % 4;//方向转换通过取模快速实现
                else {
                    // 走到下一个格子
                    i = ii;
                    j = jj;
                    break;
                }
            }
        }
        return ans;
    }

