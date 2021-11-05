#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include <stdio.h>


char	*get_next_line(int fd);
char	*ft_get_new_line(char *holder);
char	*ft_get_new_holder(char *holder);
int		ft_check_line_break(char *holder);
char	*ft_strjoin(char *holder, char *buffer);
size_t	ft_strlen(char *str);

#endif
