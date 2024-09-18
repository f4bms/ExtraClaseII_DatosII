#ifndef BST_H
#define BST_H

template <typename T>
class BST {
public:
    struct BSTNode {
        T key;
        BSTNode* left;
        BSTNode* right;
        BSTNode(T k) : key(k), left(nullptr), right(nullptr) {}
    };

    BSTNode* root;

    BST() : root(nullptr) {}

    // Método insert dentro de la clase BST
    void insert(const T& key) {
        root = insertRec(root, key);
    }

private:
    // Función recursiva para insertar en el árbol
    BSTNode* insertRec(BSTNode* node, const T& key) {
        if (node == nullptr) {
            return new BSTNode(key);
        }
        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }
        return node;
    }
};

#endif //BST_H
