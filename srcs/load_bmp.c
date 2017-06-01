/*
** load_bmp.c for  in /home/debrau_c/COURS/InfoG/LibLapin/Fil_De_Fer2/gfx_wolf3d
** 
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Dec 25 03:40:19 2015 Carl DEBRAUWERE
** Last update Sun Apr 17 18:31:34 2016 debrau_c
*/

#include "load_bmp.h"

void			draw_pix_bcl_bmp_32(t_file *img,
					    unsigned char *buf,
					    t_bunny_pixelarray *pix)
{
  int			i;
  int			k;
  int			j;
  t_color		*tmp;

  tmp = (t_color *)pix->pixels;
  i = img->h_bmp -1;
  k = 0;
  while (i >= 0)
    {
      j = 0;
      while (j < img->w_bmp)
	{
	  tmp[i * img->w_bmp + j].argb[3] = buf[k++];
	  tmp[i * img->w_bmp + j].argb[2] = buf[k++];
	  tmp[i * img->w_bmp + j].argb[1] = buf[k++];
	  tmp[i * img->w_bmp + j].argb[0] = buf[k++];
	  j++;
	}
      i--;
    }
}

void			draw_pix_bcl_bmp_24(t_file *img,
					    unsigned char *buf,
					    t_bunny_pixelarray *pix)
{
  int			i;
  int			k;
  int			j;
  t_color		*tmp;

  k = 0;
  tmp = (t_color *)pix->pixels;
  i = img->h_bmp -1;
  while (i >= 0)
    {
      j = 0;
      while (j < img->w_bmp)
	{
	  tmp[i * img->w_bmp + j].argb[2] = buf[k++];
	  tmp[i * img->w_bmp + j].argb[1] = buf[k++];
	  tmp[i * img->w_bmp + j].argb[0] = buf[k++];
	  j++;
	}
      while (k % 4 != 0) k++;
      i--;
    }
}

int			draw_pix_bmp(int fd,
				     t_file *img,
				     t_bunny_pixelarray	*pix)
{
  unsigned char		*buf;

  if ((buf = bunny_malloc((4) * (img->w_bmp * img->h_bmp))) == NULL)
    return (1);
  read(fd, buf, (4 * (img->w_bmp * img->h_bmp)));
  if (img->bpp == 32)
    draw_pix_bcl_bmp_32(img, buf, pix);
  else if (img->bpp == 24)
    draw_pix_bcl_bmp_24(img, buf, pix);
  else return (1);
  bunny_free(buf);
  return (0);
}

int			rempli_struct_bmp(t_file *img, int fd, char *path)
{
  char			bin[150];

  read(fd, &img->sign, sizeof(img->sign));
  read(fd, &img->size, sizeof(img->size));
  read(fd, &img->rsv, sizeof(img->rsv));
  read(fd, &img->offset, sizeof(img->offset));
  read(fd, &img->size_hdr, sizeof(img->size_hdr));
  read(fd, &img->w_bmp, sizeof(img->w_bmp));
  read(fd, &img->h_bmp, sizeof(img->h_bmp));
  read(fd, &img->nb_plan, sizeof(img->nb_plan));
  read(fd, &img->bpp, sizeof(img->bpp));
  read(fd, &img->compr, sizeof(img->compr));
  read(fd, &img->size_img, sizeof(img->size_img));
  read(fd, &img->reso_hori, sizeof(img->reso_hori));
  read(fd, &img->reso_vert, sizeof(img->reso_vert));
  read(fd, &img->nb_pal, sizeof(img->nb_pal));
  read(fd, &img->nb_paluse, sizeof(img->nb_paluse));
  close(fd);
  fd = open(path, O_RDONLY);
  read(fd, bin, img->offset);
  return (fd);
}

t_bunny_pixelarray	*load_bmp(char *pathname)
{
  int			fd;
  t_file		img;
  t_bunny_pixelarray	*pix;

  if ((fd = open(pathname, O_RDONLY)) < 0)
    return (NULL);
  fd = rempli_struct_bmp(&img, fd, pathname);
  if ((pix = bunny_new_pixelarray(img.w_bmp, img.h_bmp)) == NULL)
    return (NULL);
  if (draw_pix_bmp(fd, &img, pix))
      return (NULL);
  close(fd);
  return (pix);
}
