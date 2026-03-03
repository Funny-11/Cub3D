/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:28:00 by gifanell          #+#    #+#             */
/*   Updated: 2025/07/09 17:37:53 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buff(int fd, char *storage)
{
	int		read_1;
	char	*buffer;

	read_1 = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (read_1 > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		read_1 = read (fd, buffer, BUFFER_SIZE);
		if (read_1 > 0)
		{
			buffer[read_1] = '\0';
			storage = ft_strjoin_gnl(storage, buffer);
		}
	}
	free(buffer);
	if (read_1 == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if ((storage[fd] && !ft_strchr_gnl(storage[fd], '\n')) || !storage[fd])
		storage[fd] = read_buff(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = new_line(storage[fd]);
	if (!line)
		return (ft_free(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return (1);
    }

    int fds[argc - 1];
    char *line;
    int i;
    int files_remaining;

    // Apri tutti i file e salva i file descriptor
    for (i = 0; i < argc - 1; i++)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        if (fds[i] < 0)
        {
            perror("Error opening file");
            // Chiudi i file già aperti prima di uscire
            while (i > 0)
            {
                close(fds[--i]);
            }
            return (1);  // Ritorna con errore
        }
    }

    // Leggi contemporaneamente dai file finché ci sono righe disponibili
    files_remaining = argc - 1;
    while (files_remaining > 0)
    {
        for (i = 0; i < argc - 1; i++)
        {
            if (fds[i] != -1)  // Se il file non è stato già completato
            {
                line = get_next_line(fds[i]);
                if (line)
                {
                    printf("File %d: %s", i + 1, line);
                }
                else
                {
					close(fds[i]);  // Chiudi il file se non ci sono più righe
                    fds[i] = -1;    // Marca il file come completato
                    files_remaining--;
                }
				free(line);
            }
        }
    }

    return (0);
}
*/
