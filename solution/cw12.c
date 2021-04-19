#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *parent;
    struct node* left;
    struct node* right;
} node;

void insertNode(int value, struct node* root)
{
    struct node* newbie = malloc(sizeof(struct node));
    newbie->value = value;
    newbie->left = NULL;
    newbie->right = NULL;
    newbie->parent = NULL;
    if (root == NULL)
    {
        root = newbie;
        return;
    }

    if (root->value > value) {
        if (root->left)
            insertNode(value, root->left);
        else {
            root->left = newbie;
            newbie->parent = root;
        }
    }
    else {
        if (root->right)
            insertNode(value, root->right);
        else {
            root->right = newbie;
            newbie->parent = root;
        }
    }
}

void removeNode(int value, struct node* root) {
    if (!root)
        return;

    if (value < root->value)
        removeNode(root->left, value);

    else if (value > root->value)
        removeNode(root->right, value);

    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            temp->parent = root->parent;
            if (root->parent) {
                if (root->parent->left == root)
                    root->parent->left = temp;
                else
                    root->parent->right = temp;
            }
            free(root);
            return;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            temp->parent = root->parent;
            if (root->parent) {
                if (root->parent->left == root)
                    root->parent->left = temp;
                else
                    root->parent->right = temp;
            }
            free(root);
            return;
        }

        struct node* temp = root->right;
        while (temp->left)
            temp = temp->left;

        root->value = temp->value;

        removeNode(root->right, temp->value);
    }
}

struct node* getMin(struct node* root) {
    while (root->left)
        root = root->left;
    return root;
}

struct node* getMax(struct node* root) {
    while (root->right)
        root = root->right;
    return root;
}
