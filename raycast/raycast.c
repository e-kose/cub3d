/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:56:39 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/26 16:29:04 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void    ft_put_pixel(t_data *data, int x, int y, int color)
// {
//     char *dst;

//     // Pikselin bellekteki adresini hesaplıyoruz
//     dst = data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bits_per_pixel / 8));
//     *(unsigned int *)dst = color;
// }
#include <math.h>

// Basit bir yapı, ışının durduğu noktayı tutacak
typedef struct s_ray
{
    float x; // Çarpışma noktası x koordinatı
    float y; // Çarpışma noktası y koordinatı
} t_ray;

t_ray cast_ray(t_data *data, float angle)
{
    t_ray ray;
    float ray_x = data->player[0];
    float ray_y = data->player[1];
    float step_size = 1.0; // Işın uzunluğu için adım boyutu
    float dir_x = cos(angle); // X yönündeki değişim
    float dir_y = sin(angle); // Y yönündeki değişim

    while (1)
    {
        ray_x += dir_x * step_size;
        ray_y += dir_y * step_size;

        // Harita sınırlarını kontrol et
        int map_x = (int)(ray_x / 64);
        int map_y = (int)(ray_y / 64);

        if (map_x < 0 || map_x >= data->map->map_width || map_y < 0 || map_y >= data->map->map_height)
            break; // Harita dışına çıktı

        // Eğer bir duvara çarparsa
        if (data->map->map[map_y][map_x] == '1') // '1' duvarı temsil ediyor
        {
            ray.x = ray_x;
            ray.y = ray_y;
            return ray; // Çarpışma noktasını döndür
        }
    }

    // Eğer hiçbir yere çarpmazsa başlangıç noktasını döndür
    ray.x = data->player[0];
    ray.y = data->player[1];
    return ray;
}

void draw_square(t_data *data, int x, int y, int size, int color)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int pixel_index = ((y + j) * data->mlx->line_length + (x + i) * (data->mlx->bits_per_pixel / 8));
            data->mlx->addr[pixel_index + 0] = (color >> 16) & 0xFF;  // Red
            data->mlx->addr[pixel_index + 1] = (color >> 8) & 0xFF;   // Green
            data->mlx->addr[pixel_index + 2] = color & 0xFF;          // Blue
        }
    }
}
void draw_rays(t_data *data)
{
    int num_rays = 1000; // Atılacak ışın sayısı
    float angle_increment = M_PI / (num_rays / 2); // Açı artışı
    float start_angle = 60; // Başlangıç açısı

    for (int i = 0; i < num_rays; i++)
    {
        t_ray ray = cast_ray(data, start_angle);
        draw_square(data, (int)ray.x, (int)ray.y, 4, 0xFFF000); // Işın çarpışma noktasını kırmızı kare ile çiz

        start_angle += angle_increment; // Açı artır
    }
}


void draw_map(t_data *data)
{
    int x = 0;
    int y = 0;
    int size = 64;
    int color;

    for (int i = 0; i < data->map->map_height; i++)
    {
        for (int j = 0; j < data->map->map_width; j++)
        {
            if (data->map->map[i][j] == '1')
                color= 0xFFFFFF;
            else if (data->map->map[i][j] == '0')
                color = 0x000000;
            else if (data->map->map[i][j] == 'B')
                color = 0xFF0000;
            draw_square(data, x, y, size, color);
            x += size;
        }
        x = 0;
        y += size;
    }
}

int ft_key_press(int keycode, t_data *data)
{
    // Tuş kodlarına göre oyuncu pozisyonunu değiştir
    if (keycode == 53)
        ft_free(data, "NULL");
    else if (keycode == 13)
    {
        data->player[1] -= 64;
    }
    else if (keycode == 1)
        data->player[1] += 64;
    else if (keycode == 0)  
        data->player[0] -= 64;
    else if (keycode == 2)
        data->player[0] += 64;

    // Her hareketten sonra harita ve oyuncuyu yeniden çizip güncelleyin
    draw_map(data);
    draw_square(data, data->player[0], data->player[1], 32, 0XFFFF00); // Oyuncuyu çiz
    draw_rays(data);
    // Çizilen görüntüyü pencereye aktar
    mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->img, 0, 0);

    return (0);
}

void ft_init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_free(data, "Mlx init failed");
    data->mlx->win = mlx_new_window(data->mlx, data->map->map_width * 64, data->map->map_height * 64, "Cub3D");
    if (!data->mlx->win)
        ft_free(data, "Window creation failed");

    data->mlx->img = mlx_new_image(data->mlx, data->map->map_width * 64, data->map->map_height * 64);
    data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);

    draw_map(data);
    draw_square(data, data->player[0], data->player[1], 32, 0XFFFF00); // Oyuncuyu çiz

    // Işınları çiz
    draw_rays(data);

    mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->img, 0, 0);
    mlx_key_hook(data->mlx->win, ft_key_press, data);
    mlx_loop(data->mlx);
}

