#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct	s_max
{
	int value;         // MAXのvalue
	int axis_x;        // MAX値のX座標
	int axis_y;        // MAX値のY座標
	int current;       //今の行
	int *num_array[2]; //数値の二次元配列
};

struct	s_map
{
	int head_len;  //頭行の長さ
	int line_len;  //横の長さ
	int depth;     //縦の長さ(深度)
	char objct_ch; //オブジェクトの形
	char empty_ch; //空の文字
	char full_ch;  //フルの文字
	char trash;    //改行を入れるゴミ箱
};

struct s_input
{
	char *data;       //出力用
	char *data_copy1; //カウント用
	char *data_copy2; // explore用
	char *data_copy3; // explore用
	char	*extra;
};

// void	stdin_count(char *map_array, struct s_map *map);
// void	max_initialize(struct s_max *max, struct s_map *map);
// int		map_initialize(struct s_map *map, char *head_line);
// int		stdin_explore(char *data, struct s_map *map, struct s_max *max);
// int		explore(int fd, struct s_map *map, struct s_max *max);
// void	max(int *num_array, struct s_max *max);
// void	renew(int **num_array);
// void	take_place(char *ch_array, int **num_array, struct s_map *map);
// int		compare(int **num_array, int index);
// int		check_ini_info(struct s_map *map);
void	ft_read(char *data, char *dest, int size);

void	max_initialize(struct s_max *max, struct s_map *map)
{
	int	index;

	max->value = 0;
	max->axis_x = 0;
	max->axis_y = 0;
	max->current = 0;
	max->num_array[0] = (int *)malloc(sizeof(int) * map->line_len);
	if (max->num_array[0] == NULL)
		exit(1);
	max->num_array[1] = (int *)malloc(sizeof(int) * map->line_len);
	if (max->num_array[1] == NULL)
		exit(1);
	index = 0;
	while (index < map->line_len)
	{
		max->num_array[0][index] = 0;
		index++;
	}
}

int	check_ini_info(struct s_map *map)
{
	if (map->depth == 0)
		return (0);
	if (map->empty_ch == '\0')
		return (0);
	if (map->objct_ch == '\0')
		return (0);
	if (map->full_ch == '\0')
		return (0);
	if (map->empty_ch == map->objct_ch || map->empty_ch == map->full_ch
		|| map->objct_ch == map->full_ch)
		return (0);
	return (1);
}

int	map_initialize(struct s_map *map, char *head_line)
{
	int	index;
	int	temp;

	index = 0;
	temp = 0;
	while (index < (map->head_len - 3))
	{
		if (48 <= head_line[index] && head_line[index] <= 57)
			temp = (temp * 10) + (head_line[index] - '0');
		else
			return (0);
		index++;
	}
	map->depth = temp;
	map->empty_ch = head_line[map->head_len - 3];
	if (map->empty_ch < 32 || map->empty_ch == 127)
		return (0);
	index++;
	map->objct_ch = head_line[map->head_len - 2];
	if (map->objct_ch < 32 || map->objct_ch == 127)
		return (0);
	index++;
	map->full_ch = head_line[map->head_len - 1];
	if (map->full_ch < 32 || map->full_ch == 127)
		return (0);
	if (check_ini_info(map) == 0)
		return (0);
	return (1);
}

int	check(char *ch_array, struct s_map *map)
{
	int	index;

	index = 0;
	while (ch_array[index])
	{
		if (ch_array[index] != map->objct_ch
			&& (ch_array[index] != map->empty_ch))
			return(0);
		index++;
	}
	return 1;
}

int	compare(int **num_array, int index)
{
	int	mini;

	mini = num_array[0][index];
	if (num_array[0][index - 1] < mini)
		mini = num_array[0][index - 1];
	if (num_array[1][index - 1] < mini)
		mini = num_array[1][index - 1];
	return (mini);
}

void	take_place(char *ch_array, int **num_array, struct s_map *map)
{
	int	index;

	index = 0;
	while (ch_array[index])
	{
		if (index == 0)
			num_array[1][index] = 1;
		if (ch_array[index] == map->objct_ch)
			num_array[1][index] = 0;
		if (ch_array[index] == map->empty_ch && index != 0)
			num_array[1][index] = (compare(num_array, index) + 1);
		index++;
	}
	index = 0;
}

void	put_max(int *num_array, struct s_max *max, struct s_map *map)
{
	int	index;

	index = 0;
	while (index < map->line_len)
	{
		if (num_array[index] > max->value)
		{
			max->axis_x = index;
			max->axis_y = max->current;
			max->value = num_array[index];
		}
		index++;
	}
}

void	ft_renew(int **num_array, struct s_map *map)
{
	int	index;

	index = 0;
	while (index < map->line_len)
	{
		num_array[0][index] = num_array[1][index];
		index++;
	}
}

int	std_ex_pro(char *data, char *ch_array, struct s_map *map, struct s_max *max)
{
	int	index;
	index = 0;
	while (index < map->depth)
	{
		ft_read(data, ch_array, map->line_len);
		ft_read(data, &map->trash, 1);
		if (map->trash != '\n')
			return (0);
		if(check(ch_array, map) == 0)
			return 0;
		take_place(ch_array, max->num_array, map);
		put_max(&max->num_array[1][0], max, map);
		ft_renew(max->num_array, map);
		max->current++;
		index++;
	}
	return (1);
}

void	ft_read(char *data, char *dest, int size)
{
	int	i;

	i = 0;
	while (size > i)
	{
		dest[i] = data[i];
		i++;
	}
	i = 0;
	while (data[size + i])
	{
		data[i] = data[size + i];
		i++;
	}
}
int	stdin_explore(char *data, struct s_map *map, struct s_max *max)
{
	char	*head_line;
	char	*ch_array;
	int		result;
	int		i;

	// printf("%d\n", map->head_len);
	i = map->head_len;
	head_line = (char *)malloc(map->head_len + 1);
	if (head_line == NULL)
		exit(0);
	ch_array = (char *)malloc(map->line_len + 1);
	if (ch_array == NULL)
		exit(0);
	ft_read(data, head_line, map->head_len);
	ft_read(data, &map->trash, 1);
	result = map_initialize(map, head_line);
	if (result == 0)
		return (0);
	max_initialize(max, map);
	result = std_ex_pro(data, ch_array, map, max);
	if (result == 0)
		return (0);
	free(ch_array);
	free(head_line);
	// free(max->num_array);
	return (1);
}

void	stdin_count(char *data, struct s_map *map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == '\n')
			break ;
		count++;
		i++;
	}
	map->head_len = count;
	// printf("head_count :%d\n", count);
	count = 0;
	i++;
	while (data[i] != '\0')
	{
		if (data[i] == '\n')
			break ;
		count++;
		i++;
	}
	map->line_len = count;
	// printf("line_count :%d\n", count);
}

void	std_display(char *data, struct s_map *map, struct s_max *max)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (data[i])
	{
		if ((x >= (max->axis_x - (max->value - 1))) && (max->axis_x >= x)
			&& (y >= (max->axis_y + 1 - (max->value - 1))) && (max->axis_y
				+ 1 >= y))
			write(1, &map->full_ch, 1);
		else if (data[i] == '\n')
		{
			x = 0;
			y++;
			write(1, "\n", 1);
			i++;
			continue ;
		}
		else
			write(1, &data[i], 1);
		x++;
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(dest);
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *origin, char *extra) //ファイル読み込み
{
	char *data;

	data = malloc(ft_strlen(origin) + ft_strlen(extra) + 1);
	if (data == NULL)
		exit(1);
	ft_strcpy(data, origin);
	ft_strcat(data, extra);
	free(origin);
	return (data);
}
int	ex_process(int fd, char *ch_array, struct s_map *map, struct s_max *max)
{
	int	index;

	index = 0;
	while (index < map->depth)
	{
		if (read(fd, ch_array, map->line_len) < 1)
		{
			printf("%d",54);
			return (0);
		}
		if (read(fd, &map->trash, 1) < 1)
		{
			printf("%d",24);
			return (0);
		}
		if (map->trash != '\n')
			return (0);
		if (check(ch_array, map) == 0)
		{
			return (0);
		}
		take_place(ch_array, max->num_array, map);
		put_max(&max->num_array[1][0], max, map);
		ft_renew(max->num_array, map);
		max->current++;
		index++;
	}
	return (1);
}

int	explore(int fd, struct s_map *map, struct s_max *max)
{
	char	*head_line;
	char	*ch_array;
	int		result;

	head_line = (char *)malloc(map->head_len + 1);
	if (head_line == NULL)
		return (0);
	ch_array = (char *)malloc(map->line_len + 1);
	if (ch_array == NULL)
		return (0);
	if (read(fd, head_line, map->head_len) < 1)
		return (0);
	if (read(fd, &map->trash, 1) < 1)
		return (0);
	result = map_initialize(map, head_line);
	if (result == 0)
	{
		return (0);
	}
	max_initialize(max, map);
	result = ex_process(fd, ch_array, map, max);
	printf ("%d",34);
	if (result == 0)
		return (0);
	free(head_line);
	free(ch_array);
	return (1);
}

void	count(int fd, struct s_map *map)
{
	char	letter;
	int		count;

	count = 0;
	while (read(fd, &letter, 1) > 0)
	{
		if (letter == '\n')
			break ;
		count++;
	}
	map->head_len = count;
	count = 0;
	while (read(fd, &letter, 1) > 0)
	{
		if (letter == '\n')
			break ;
		count++;
	}
	map->line_len = count;
}

void	display(int fd, struct s_map *map, struct s_max *max)
{
	char	buffer[1];
	int		x;
	int		y;
	int	flag;

	x = 0;
	y = 0;
	flag = 1;
	buffer[0] = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (flag == 1)
		{
			if( buffer[0] == '\n')
				flag = 0;
			continue;
		}
		else if ((x >= (max->axis_x - (max->value - 1))) && (max->axis_x >= x)
			&& (y >= (max->axis_y - (max->value - 1))) && (max->axis_y
				 >= y))
			write(1, &map->full_ch, 1);
		else if (buffer[0] == '\n')
		{
			x = 0;
			y++;
			write(1, "\n", 1);
			continue ;
		}
		else
			write(1, &buffer[0], 1);
		x++;
	}
}

int	std_check_depth(char *data)
{	
	char buf[1];
	int row;

	row = -1;
	while(1)
	{
		ft_read(data,buf,1);
		if (buf[0])
			return(row);
		if (buf[0] == '\n')
			row++;
	}
	return (row);
}

int	check_depth(int fd)
{
	char buf[1];
	int row;

	row = -1;
	while(read(fd,buf,1))
	{
		if (buf[0] == '\n')
			row++;
	}
	return (row);
}

int	case_input(struct s_input *input, struct s_map *map_info, struct s_max *max_info)
{
	int result;            //エラー処理用の変数
	int fd;
	int i;

	fd = 0;
	i = 0;
	while (read(fd, input->extra, 1024) > 0)
	{
		input->data = ft_strjoin(input->data, input->extra);
		input->data_copy1 = ft_strjoin(input->data_copy1, input->extra);
		input->data_copy2 = ft_strjoin(input->data_copy2, input->extra);
		input->data_copy3 = ft_strjoin(input->data_copy3, input->extra);
		while (input->extra[i])
		{
			input->extra[i] = 0;
			i++;
		}
	}
	stdin_count(input->data_copy1, map_info); // 1行分のバイト数を読み取る。
	free(input->data_copy1);
	if (std_check_depth(input->data_copy3)!= map_info->depth)
			return (0); 
	free(input->data_copy3);
	result = stdin_explore(input->data_copy2, map_info, max_info); // max情報を書き換える
	if (result == 0)
		return (0); // exploreが失敗した、有効なマップではない場合
	free(input->data_copy2);
	std_display(input->data, map_info, max_info); //結果を表示<<<<-------要作成
	if (result == 0)
		return (0); //ディスプレイできない場合
					// 標準入力の場合
	free(input->data);
	return (1);
}

int case_file(int argc, char **argv, struct s_map *map_info, struct s_max *max_info)
{
	int fd;
	int index;
	int result;

	index = 1;
	while (index < argc)
	{
		fd = open(argv[index], O_RDONLY, 0666); // open一回目
		if (fd == -1)
		{
			printf("%d\n",1);
			write(1,"map error\n",10);
			index++;
			continue;
		}                            //マップがひらけない場合
		count(fd, map_info);
		close(fd);                          //一旦ファイルを閉じる
		fd = open(argv[index], O_RDONLY, 0666); // open二回目
		if (fd == -1)
			exit (1);                                //マップがひらけない場合
		result = explore(fd, map_info, max_info); // max情報を書き換える
		if (result == 0)
		{
			printf("%d\n",2);
			write(1,"map error\n",10);
			index++;
			continue;
		}                              // exploreが失敗した、有効なマップではない場合
		close(fd);   
		fd = open(argv[index], O_RDONLY, 0666); // open二回目
		if (fd == -1)
			exit (1);
		if (check_depth(fd) != map_info->depth)
		{
			printf("%d\n",0);
			return (0);   
		}              // 1行分のバイト数を読み取る。
		printf("%d\n",34123);
		close(fd);                               //一旦ファイルを閉じる
		fd = open(argv[index], O_RDONLY, 0666); // open三回目
		if (fd == -1)
			exit (1);                  //マップがひらけない場合
		display(fd, map_info, max_info); //結果を表示<<<<-------要作成
		close(fd);   //ファイルを閉じる
		index++;     //次のファイルへ
	}
	return(1);
}

int	main(int argc, char **argv)
{
	int		i;
	struct s_max max_info; // max値に関する情報
	struct s_map map_info; // mapに関する情報
	struct s_input input;
	i = 0;
	input.data = malloc(1);
	input.data_copy1 = malloc(1);
	input.data_copy2 = malloc(1);
	input.extra = malloc(1024 + 1);
	if (argc == 1)
	{
		if (case_input(&input, &map_info, &max_info))
			return (0);
		write(1,"map error\n",10);
		return (1);
	}
	else
	{
		if (case_file(argc, argv, &map_info, &max_info))
			return (0);
		return (1);
	}
}

