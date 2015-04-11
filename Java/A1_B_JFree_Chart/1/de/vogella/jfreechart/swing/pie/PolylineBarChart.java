/**
 * A simple demonstration application showing how to create a bar chart overlaid
 * with a line chart.
 * Original source : http://androphil.tistory.com/entry/JFreeChart-%EB%AC%B4%EB%A3%8C-%EC%9E%90%EB%B0%94-%EC%B0%A8%ED%8A%B8-%EC%9D%B4%EC%9A%A9-%EA%B4%80%EB%A0%A8
 * Most of the codes are direct copy from the source above
 * Data source :http://open.canada.ca/data/en/dataset/81f6c8e6-ffee-4c20-8cbf-c06dc2b233e6
 *
 * Student Name : Jung Geon Choi
 * 
 */


package de.vogella.jfreechart.swing.pie;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Paint;

import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.CategoryAxis;
import org.jfree.chart.axis.CategoryLabelPositions;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.labels.CategoryItemLabelGenerator;
import org.jfree.chart.labels.ItemLabelAnchor;
import org.jfree.chart.labels.ItemLabelPosition;
import org.jfree.chart.labels.StandardCategoryItemLabelGenerator;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.DatasetRenderingOrder;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.category.BarRenderer;
import org.jfree.chart.renderer.category.CategoryItemRenderer;
import org.jfree.chart.renderer.category.LineAndShapeRenderer;
import org.jfree.chart.renderer.category.StandardBarPainter;
import org.jfree.chart.title.TextTitle;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.ui.GradientPaintTransformType;
import org.jfree.ui.HorizontalAlignment;
import org.jfree.ui.StandardGradientPaintTransformer;
import org.jfree.ui.TextAnchor;


public class PolylineBarChart {

	public static void main(final String[] args) {
		PolylineBarChart demo = new PolylineBarChart();
		JFreeChart chart = demo.getChart();
		ChartFrame frame1=new ChartFrame("Bar Chart",chart);
		frame1.setSize(800,400); 
		frame1.setVisible(true);
	}

	public JFreeChart getChart() {

		//data container
		DefaultCategoryDataset dataset1 = new DefaultCategoryDataset();                // bar chart 1
		DefaultCategoryDataset dataset12 = new DefaultCategoryDataset();         // bar chart 2
		DefaultCategoryDataset dataset2 = new DefaultCategoryDataset();                // line chart 1

		// data
		dataset1.addValue(332, "Snow Fall in cm", "St. John's");
		dataset1.addValue(311, "Snow Fall in cm", "Charlottetown");
		dataset1.addValue(230, "Snow Fall in cm", "Halifax");
		dataset1.addValue(276, "Snow Fall in cm", "Fredericton");
		dataset1.addValue(315, "Snow Fall in cm", "Qubec");
		dataset1.addValue(217, "Snow Fall in cm", "Montrel");
		dataset1.addValue(235, "Snow Fall in cm", "Ottawa");
		dataset1.addValue(115, "Snow Fall in cm", "Toronto");
		dataset1.addValue(110, "Snow Fall in cm", "Winnipeg");
		dataset1.addValue(105, "Snow Fall in cm", "Regina");
		dataset1.addValue(121, "Snow Fall in cm", "Edmonton");
		dataset1.addValue(126, "Snow Fall in cm", "Calgary");
		dataset1.addValue(48, "Snow Fall in cm", "Vancouver");
		dataset1.addValue(43, "Snow Fall in cm", "Victoria");
		dataset1.addValue(145, "Snow Fall in cm", "Whitehorse");
		dataset1.addValue(151, "Snow Fall in cm", "Yellowknife");

		// 그래프 2       
		dataset12.addValue(1513, "Precipitation in mm", "St. John's");
		dataset12.addValue(1173, "Precipitation in mm", "Charlottetown");
		dataset12.addValue(1452, "Precipitation in mm", "Halifax");
		dataset12.addValue(1143, "Precipitation in mm", "Fredericton");
		dataset12.addValue(1230, "Precipitation in mm", "Qubec");
		dataset12.addValue(978, "Precipitation in mm", "Montrel");
		dataset12.addValue(943, "Precipitation in mm", "Ottawa");
		dataset12.addValue(792, "Precipitation in mm", "Toronto");
		dataset12.addValue(513, "Precipitation in mm", "Winnipeg");
		dataset12.addValue(388, "Precipitation in mm", "Regina");
		dataset12.addValue(482, "Precipitation in mm", "Edmonton");
		dataset12.addValue(412, "Precipitation in mm", "Calgary");
		dataset12.addValue(1199, "Precipitation in mm", "Vancouver");
		dataset12.addValue(883, "Precipitation in mm", "Victoria");
		dataset12.addValue(267, "Precipitation in mm", "Whitehorse");
		dataset12.addValue(280, "Precipitation in mm", "Yellowknife");

		// 그래프 3       
		dataset2.addValue(215.6, "Average wet day in a year", "St. John's");
		dataset2.addValue(184.2, "Average wet day in a year", "Charlottetown");
		dataset2.addValue(156, "Average wet day in a year", "Halifax");
		dataset2.addValue(181, "Average wet day in a year", "Fredericton");
		dataset2.addValue(163, "Average wet day in a year", "Qubec");
		dataset2.addValue(162, "Average wet day in a year", "Montrel");
		dataset2.addValue(145, "Average wet day in a year", "Ottawa");
		dataset2.addValue(123, "Average wet day in a year", "Toronto");
		dataset2.addValue(114, "Average wet day in a year", "Winnipeg");
		dataset2.addValue(124, "Average wet day in a year", "Regina");
		dataset2.addValue(113, "Average wet day in a year", "Edmonton");
		dataset2.addValue(166, "Average wet day in a year", "Calgary");
		dataset2.addValue(154, "Average wet day in a year", "Vancouver");
		dataset2.addValue(122, "Average wet day in a year", "Victoria");
		dataset2.addValue(122, "Average wet day in a year", "Whitehorse");
		dataset2.addValue(118, "Average wet day in a year", "Yellowknife");


		final BarRenderer renderer = new BarRenderer();
		final BarRenderer renderer12 = new BarRenderer();
		final LineAndShapeRenderer renderer2 = new LineAndShapeRenderer();


		final CategoryItemLabelGenerator generator = new StandardCategoryItemLabelGenerator();
		final ItemLabelPosition p_center = new ItemLabelPosition(
				ItemLabelAnchor.CENTER, TextAnchor.CENTER
				);
		final ItemLabelPosition p_below = new ItemLabelPosition(
				ItemLabelAnchor.OUTSIDE6, TextAnchor.TOP_LEFT
				);
		Font f = new Font("Gulim", Font.BOLD, 5);
		Font axisF = new Font("Gulim", Font.PLAIN, 5);


		renderer.setBaseItemLabelGenerator(generator);
		renderer.setBaseItemLabelsVisible(true);
		renderer.setBasePositiveItemLabelPosition(p_center);
		renderer.setBaseItemLabelFont(f);

		renderer.setSeriesPaint(0, new Color(0,162,255));

		// Graph2     
		renderer12.setSeriesPaint(0, new Color(232,168,255));
		renderer12.setBaseItemLabelFont(f);
		renderer12.setBasePositiveItemLabelPosition(p_center);
		renderer12.setBaseItemLabelGenerator(generator);
		renderer12.setBaseItemLabelsVisible(true);

		// graph 3       
		renderer2.setBaseItemLabelGenerator(generator);
		renderer2.setBaseItemLabelsVisible(true);
		renderer2.setBaseShapesVisible(true);
		renderer2.setDrawOutlines(true);
		renderer2.setUseFillPaint(true);
		renderer2.setBaseFillPaint(Color.WHITE);
		renderer2.setBaseItemLabelFont(f);
		renderer2.setBasePositiveItemLabelPosition(p_below);
		renderer2.setSeriesPaint(0,new Color(219,121,22));
		renderer2.setSeriesStroke(0,new BasicStroke(
				2.0f,
				BasicStroke.CAP_ROUND,
				BasicStroke.JOIN_ROUND,
				3.0f)
				);

		// plot 
		final CategoryPlot plot = new CategoryPlot();

		// plot 
//		plot.setDataset(dataset1);
//		plot.setRenderer(renderer); //un comment and comment other rendering lines will show snowfall graph
		plot.setDataset(1,dataset12);
		plot.setRenderer(1,renderer12);
		plot.setDataset(2, dataset2);
		plot.setRenderer(2, renderer2);

		// plot 
		plot.setOrientation(PlotOrientation.VERTICAL);            
		plot.setRangeGridlinesVisible(true);                       
		plot.setDomainGridlinesVisible(true);                     

		
		plot.setDatasetRenderingOrder(DatasetRenderingOrder.FORWARD);

		
		plot.setDomainAxis(new CategoryAxis());           
		plot.getDomainAxis().setTickLabelFont(axisF); 
		plot.getDomainAxis().setCategoryLabelPositions(CategoryLabelPositions.STANDARD);    

	
		plot.setRangeAxis(new NumberAxis());                
		plot.getRangeAxis().setTickLabelFont(axisF);  


		final JFreeChart chart = new JFreeChart(plot);
		        chart.setTitle("Weather conditions in capital");

		return chart;
	}

}
