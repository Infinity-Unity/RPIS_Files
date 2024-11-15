//Выполнил студент 1РП-ИС Гамидов Абдул
//ошибок в функциях нет
//любое совпадение в других кодах, я не несу ответственность
//код также выложил на гитхаб readme читать обязательно!!!
//https://github.com/Infinity-Unity/RPIS_Files/blob/main/c_array_t.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t type_size_;
    size_t size_;
    void *p_buffer_;
} c_array_t;

c_array_t *c_arr_init(size_t type_size) {
    c_array_t *arr = (c_array_t *)malloc(sizeof(c_array_t));
    arr->type_size_ = type_size;
    arr->size_ = 0;
    arr->p_buffer_ = NULL;
    return arr;
}

c_array_t *c_arr_init_size(size_t type_size, size_t size) {
    c_array_t *arr = c_arr_init(type_size);
    arr->size_ = size;
    arr->p_buffer_ = malloc(size * type_size);
    return arr;
}

c_array_t *c_arr_init_size_val(size_t type_size, size_t size, const void *p_data) {
    c_array_t *arr = c_arr_init_size(type_size, size);
    for (size_t i = 0; i < size; i++) {
        memcpy((char *)arr->p_buffer_ + i * type_size, p_data, type_size);
    }
    return arr;
}

c_array_t *c_arr_init_from(size_t type_size, const void *p_src, size_t size) {
    c_array_t *arr = c_arr_init_size(type_size, size);
    memcpy(arr->p_buffer_, p_src, size * type_size);
    return arr;
}

c_array_t *c_arr_copy(const c_array_t *p_other) {
    c_array_t *arr = c_arr_init_size(p_other->type_size_, p_other->size_);
    memcpy(arr->p_buffer_, p_other->p_buffer_, p_other->size_ * p_other->type_size_);
    return arr;
}

void c_arr_copy_assign(c_array_t *p_self, const c_array_t *p_other) {
    if (p_self->p_buffer_ != NULL) free(p_self->p_buffer_);
    p_self->type_size_ = p_other->type_size_;
    p_self->size_ = p_other->size_;
    p_self->p_buffer_ = malloc(p_other->size_ * p_other->type_size_);
    memcpy(p_self->p_buffer_, p_other->p_buffer_, p_other->size_ * p_other->type_size_);
}

void c_arr_destroy(c_array_t *p_self) {
    if (p_self->p_buffer_ != NULL) 
    {
        free(p_self->p_buffer_);
    }
    free(p_self);
}

void *c_arr_get(const c_array_t *p_self, size_t idx) {
    if (idx >= p_self->size_) return NULL;
    return (char *)p_self->p_buffer_ + idx * p_self->type_size_;
}

void c_arr_set(const c_array_t *p_self, size_t idx, const void *p_data) {
    if (idx >= p_self->size_) return;
    memcpy((char *)p_self->p_buffer_ + idx * p_self->type_size_, p_data, p_self->type_size_);
}


void *c_arr_at(const c_array_t *p_self, size_t idx) {
    if (idx >= p_self->size_) {
        fprintf(stderr, "Index out\n");
        exit(1);
    }
    return (char *)p_self->p_buffer_ + idx * p_self->type_size_;
}

void *c_arr_front(const c_array_t *p_self) {
    return p_self->p_buffer_;
}

void *c_arr_back(const c_array_t *p_self) {
    return (char *)p_self->p_buffer_ + (p_self->size_ - 1) * p_self->type_size_;
}

void *c_arr_data(const c_array_t *p_self) {
    return p_self->p_buffer_;
}

int c_arr_empty(const c_array_t *p_self) {
    return p_self->size_ == 0;
}

size_t c_arr_size(const c_array_t *p_self) {
    return p_self->size_;
}

size_t c_arr_type_size(const c_array_t *p_self) {
    return p_self->type_size_;
}

void c_arr_fill(c_array_t *p_self, const void *p_data) {
    for (size_t i = 0; i < p_self->size_; i++) {
        memcpy((char *)p_self->p_buffer_ + i * p_self->type_size_, p_data, p_self->type_size_);
    }
}

void c_arr_swap(c_array_t *p_self, c_array_t *p_other) {
    size_t temp_size = p_self->size_;
    void *temp_buffer = p_self->p_buffer_;
    size_t temp_type_size = p_self->type_size_;

    p_self->size_ = p_other->size_;
    p_self->p_buffer_ = p_other->p_buffer_;
    p_self->type_size_ = p_other->type_size_;

    p_other->size_ = temp_size;
    p_other->p_buffer_ = temp_buffer;
    p_other->type_size_ = temp_type_size;

}


typedef int (*c_comparator)(const void *, const void *);

int c_arr_equal(const c_array_t *p_self, const c_array_t *p_other, c_comparator cmp) {
    if (p_self->size_ != p_other->size_ || p_self->type_size_ != p_other->type_size_) return 0;
    for (size_t i = 0; i < p_self->size_; i++) {
        if (cmp((char *)p_self->p_buffer_ + i * p_self->type_size_, (char *)p_other->p_buffer_ + i * p_other->type_size_) != 0) return 0;
    }
    return 1;
}

int c_arr_not_equal(const c_array_t *p_self, const c_array_t *p_other, c_comparator cmp) {
    return !c_arr_equal(p_self, p_other, cmp);
}

typedef void (*c_print_func)(const void *);

void c_arr_print(const c_array_t *p_self, c_print_func pf) {
    for (size_t i = 0; i < p_self->size_; i++) {
        pf((char *)p_self->p_buffer_ + i * p_self->type_size_);
    }
}

int main() {


}

