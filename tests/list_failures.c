#include "libft.h"
#include <assert.h>
#include <stdio.h>
void *__real_malloc(size_t size);
static int fail_at = -1, allocations, deleted, mapped;
void *__wrap_malloc(size_t size)
{
    if (allocations++ == fail_at)
        return NULL;
    return __real_malloc(size);
}
static void *copy(void *content)
{
    int *p = __real_malloc(sizeof(int));
    assert(p);
    *p = content ? *(int *)content : 0;
    mapped++;
    return p;
}
static void destroy(void *content)
{
    deleted++;
    free(content);
}
static void *empty(void *content)
{
    (void)content;
    return NULL;
}
int main(void)
{
    t_list a = {NULL, NULL}, b = {NULL, NULL}, c = {NULL, NULL};
    t_list *out;
    int i;
    a.next = &b;
    b.next = &c;
    out = ft_lstnew(NULL);
    assert(out && out->content == NULL && out->next == NULL);
    free(out);
    allocations = 0;
    fail_at = 0;
    assert(ft_lstnew(&i) == NULL);
    for (i = 0; i < 3; i++) {
        allocations = deleted = mapped = 0;
        fail_at = i;
        assert(ft_lstmap(&a, copy, destroy) == NULL);
        assert(mapped == i + 1 && deleted == mapped);
    }
    fail_at = -1;
    deleted = mapped = 0;
    out = ft_lstmap(&a, copy, destroy);
    assert(ft_lstsize(out) == 3);
    ft_lstclear(&out, destroy);
    assert(!out && mapped == 3 && deleted == 3);
    deleted = 0;
    out = ft_lstmap(&a, empty, destroy);
    assert(ft_lstsize(out) == 3 && !out->content);
    ft_lstclear(&out, destroy);
    assert(deleted == 3);
    assert(ft_lstmap(NULL, copy, destroy) == NULL);
    assert(ft_lstmap(&a, NULL, destroy) == NULL);
    assert(ft_lstmap(&a, copy, NULL) == NULL);
    puts("NULL content, list mapping and malloc-failure checks passed");
}
