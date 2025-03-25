/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int index;

    void preorder(TreeNode* node, vector<string>& res) {
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        preorder(node->left, res);
        preorder(node->right, res);
    }
    string join(const vector<string> &arr, char delim) {
        if (arr.empty()) return "";
        ostringstream oss;
        oss << arr[0];
        for (int i = 1; i < (int)arr.size(); i++) {
            oss << delim << arr[i];
        }
        return oss.str();
    }

    TreeNode* buildTree(const vector<string>& nodeValues) {
        if (nodeValues[index] == "N") {
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodeValues[index]));
        index++;
        node->left = buildTree(nodeValues);
        node->right = buildTree(nodeValues);
        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> result;
        string current;
        for (char c : s) {
            if (c == delim) {
                result.push_back(current);
                current.clear();
            } else {
                current.push_back(c);
            }
        }
        result.push_back(current);
        return result;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        preorder(root, res);
        return join(res, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodeValues = split(data, ',');
        index = 0;
        return buildTree(nodeValues);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));