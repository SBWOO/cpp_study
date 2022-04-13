#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/time.h>   // TicToc

int main (int argc, char* argv[])
{

  // argument parsing && pointcloud loading
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_to_align(new pcl::PointCloud<pcl::PointXYZ>);
  if(argc < 3) {
    std::cout << "Please use the following format: \n" << std::endl;
    std::cout << "\t" << argv[0] << " [pcd file1] [pcd file2] [itr num] [x_offset] [y_offset]\n" << endl;
    std::cout << "Usage Example: \n" << std::endl;
    std::cout << "\t" << argv[0] << " input_file1.pcd input_file2.pcd 100\n" << endl;
    PCL_ERROR ("Provide one pcd file. \n");
    return (-1);
  }
  if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud1) < 0)
  {
    PCL_ERROR("Error loading cloud %s.\n", argv[1]);
    return (-1);
  }

  if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[2], *cloud2) < 0)
  {
    PCL_ERROR("Error loading cloud %s.\n", argv[2]);
    return (-1);
  }
  if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[2], *cloud2_to_align) < 0)
  {
    PCL_ERROR("Error loading cloud %s.\n", argv[2]);
    return (-1);
  }

  // ICP option parameter parsing
  // default value : 100, 0, 0
  int itr = 100;
  float x_offset = 0;
  float y_offset = 0;
  float yaw_offset = 0;

  if(argc > 3){ // iteration number
    itr = atoi(argv[3]);
  }
  if(argc > 4){ // offset x
    x_offset = atof(argv[4]);
  }

  if(argc > 5){ // offset y
    y_offset = atof(argv[5]);
  }

  if(argc> 6){
    yaw_offset = 3.14159 * atof(argv[6])/180;
  }
  // argument print
  std::cout << "Loading " << cloud1->size () << " data points to icp fixed cloud ..." << std::endl;
  std::cout << "Loading " << cloud2->size () << " data points to icp align cloud ..." << std::endl;
  std::cout << "*** ICP parameter settings ***" << std::endl;
  std::cout << "ICP Max iteration " << itr << " iteration" << std::endl;
  std::cout << "x offset to align cloud: " << x_offset << std::endl;
  std::cout << "y offset to align cloud: " << y_offset << std::endl;
  // Defining a rotation matrix and translation vector
  Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity();

  // translation offset
  transformation_matrix (0, 3) = x_offset;
  transformation_matrix (1, 3) = y_offset;
  transformation_matrix (2, 3) = 0.0;
  transformation_matrix (0, 0) =  cos(yaw_offset);
  transformation_matrix (0, 1) = -sin(yaw_offset);
  transformation_matrix (1, 0) =  sin(yaw_offset);
  transformation_matrix (1, 1) =  cos(yaw_offset);
  pcl::PointCloud<pcl::PointXYZ>::Ptr offset_cloud2(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::transformPointCloud(*cloud2, *offset_cloud2, transformation_matrix);

  // start icp
  std::cout << "\n=========================================" << std::endl;
  std::cout << "\tIterative Closest Point" << std::endl;
  std::cout << "=========================================" << std::endl;
  pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
  icp.setInputSource(offset_cloud2);  // pointcloud to move align
  icp.setInputTarget(cloud1);  // pointcloud to fix
  icp.setMaximumIterations(itr);
  icp.align(*cloud2_to_align);

  // print ICP result
  std::cout << "has converged:" << icp.hasConverged() << " \t score: " <<
  icp.getFitnessScore() << std::endl;
  std::cout << "ICP transformation result: \n"<< icp.getFinalTransformation() << std::endl;

  // process transformation
  Eigen::Matrix4d total_transform = icp.getFinalTransformation().cast<double>() * transformation_matrix;
  pcl::PointCloud<pcl::PointXYZ>::Ptr total_cloud2(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::transformPointCloud(*cloud2, *total_cloud2, total_transform);

  std::cout << "\n=========================================" << std::endl;
  std::cout << "\tVisualization" << std::endl;
  std::cout << "=========================================" << std::endl;
  std::cout << "blue   : input pointcloud 1" << std::endl;
  std::cout << "red    : input pointcloud 2" << std::endl;
  std::cout << "green  : pointcloud 2 with offset transform" << std::endl;
  std::cout << "white  : ICP from green pointcloud" << std::endl;
  std::cout << "orange : final transformed from input pointcloud 2" << std::endl;

  std::cout << "\n=========================================" << std::endl;
  std::cout << "\tResult analysis" << std::endl;
  std::cout << "=========================================" << std::endl;
  std::cout << "SE(3) transformation matrix :" << std::endl;
  std::cout << total_transform << std::endl;
  std::cout << "x y z & quaternion form [x y z qx qy qz qw] :" << std::endl;
  std::cout << "[ "<< total_transform(0, 3) << " " << total_transform(1, 3) << " " << total_transform(2, 3) << " ";

  Eigen::Matrix3d so_3 = total_transform.block<3, 3>(0, 0);
  Eigen::Quaterniond q(so_3);
  std::cout << q.x() << " " << q.y() << " " << q.z() << " " << q.w() << " ]"<< std::endl;

  // viewer for validation check
  pcl::visualization::PCLVisualizer viewer("PCL Viewer");

  // point cloud blue for fixed cloud
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud1_color_h (
    cloud1,
    20, 20, 180);
  viewer.addPointCloud(cloud1, cloud1_color_h, "cloud1");

  // point cloud red for cloud to be aligned
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud2_color_h (
    cloud2,
    180, 20, 20);
  viewer.addPointCloud(cloud2, cloud2_color_h, "alignedcloud");

  // point cloud green for offset transformation
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> offset_color_h (
    offset_cloud2,
    20, 180, 20);
  viewer.addPointCloud(offset_cloud2, offset_color_h, "offsetcloud");

  // point cloud white for aligned pointcloud
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> align_color_h (
    cloud2_to_align,
    180, 180, 180);
  viewer.addPointCloud(cloud2_to_align, align_color_h, "aligncloud");

  // point cloud orange for aligned from original cloud before offset
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> total_color_h (
    total_cloud2,
    180, 110, 20);
  viewer.addPointCloud(total_cloud2, total_color_h, "totaltransform");

  viewer.spin();

  while(!viewer.wasStopped());

  return (0);
}

