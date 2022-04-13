#include <iostream>
#include <string>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int main (int argc, char * argv[])
{
  pcl::PointCloud<pcl::PointXYZ> cloud; // pointcloud 구조체 생성

  // 파라미터 설정
  cloud.width = 10;
  cloud.height = 1;
  cloud.is_dense = false;
  cloud.points.resize (cloud.width * cloud.height);

  // 노가다 시작

  // 1
  cloud.points[1].x = 1.306;
  cloud.points[1].y = 0.725;
  cloud.points[1].z = 0.040;

  // 2
  cloud.points[2].x = 1.297;
  cloud.points[2].y = 0.107;
  cloud.points[2].z = -0.045;

  // 3
  cloud.points[3].x = 6.035;
  cloud.points[3].y = -0.145;
  cloud.points[3].z = -0.149;

  // 4
  cloud.points[4].x = 9.794;
  cloud.points[4].y = -8.932;
  cloud.points[4].z = -0.254;

  // 5
  cloud.points[5].x = 14.414;
  cloud.points[5].y = -20.173;
  cloud.points[5].z = -0.346;

  // 6
  cloud.points[6].x = 17.158;
  cloud.points[6].y = -28.818;
  cloud.points[6].z = -0.412;

  // 7
  cloud.points[7].x = 19.512;
  cloud.points[7].y = -30.912;
  cloud.points[7].z = -0.494;

  // 8
  cloud.points[8].x = 10.447;
  cloud.points[8].y = -33.733;
  cloud.points[8].z = -0.267;

  // 9
  cloud.points[9].x = 27.444;
  cloud.points[9].y = -28.949;
  cloud.points[9].z = -0.808;

  // 10
  cloud.points[0].x = 15.832;
  cloud.points[0].y = -26.304;
  cloud.points[0].z = -0.482;

  for (std::size_t i = 0; i < cloud.points.size(); ++i)
  {
    std::cout << " " << cloud.points[i].x << " " << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;
  }

  pcl::visualization::CloudViewer viewer("PCL Viewer");
  viewer.showCloud(cloud.makeShared());

  while(!viewer.wasStopped());

  std::string file_name = "CAM_MAP.pcd";
  std::cout << "data saved to " << file_name << std::endl;
  pcl::io::savePCDFileASCII (file_name, cloud);

  return 0;
}
