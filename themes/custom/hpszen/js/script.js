/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.hpszen = {
    attach: function (context, settings) {
      $('.slides', context)
      .once('hpszen', function() {

        if ("cycle" in $.fn) {

          Drupal.theme.hpszenCyclingPager = function () {
            return '<div class="pager"></div>';
          };

          Drupal.theme.hpszenCyclingPagerItem = function (index, slide) {
            var slide = $(slide),
                alt = slide.find('h2').text() || '',
                image = slide.find('.field-type-image img');
            return '<a title="' + Drupal.t('Slide number @index.', { '@index': index + 1 }) + '" href="#"><img src="' + image.attr('src') + '" alt="' + alt + '"/></a>';
          };

          // Assume slides are block content:
          var slides = $(this),
              images = $(this).find('.field-type-image img');
          slides.closest('.block').addClass('cycling');

          images.one('load', function () {
            positionImage(this);
          }).each(function () {
            if (this.complete) $(this).load();
          });

          slides.parent().append(Drupal.theme('hpszenCyclingPager'));

          slides.cycle({
            pager:  '.pager',
            pagerAnchorBuilder: pagerItem,
            pause: 1,
            speed: 1000,
            fastOnEvent: 200,
            delay: -2000,
            timeout: 15000,
            fx: 'scrollLeft',
            after: function () {
              positionImage($(this).find('.field-type-image img')[0]);
            }
          });

          function pagerItem(index, slide) {
            return Drupal.theme('hpszenCyclingPagerItem', index, slide);
          }

          $(window).bind('resize', function () {
            slides.each(function () {
              $(this).width($(this).closest('.block').width());
              positionImage($(this).find('.field-type-image img')[0]);
            });
          });

          // Called on image load, window resize and after slide transition.
          function positionImage(image) {
            var container = $(image).closest('.field-type-image'),
                showing = (container.height() / image.height),
                margin  = 0;
            if (!container.width() > 0 || !image.width > 0) return; // Stop if slide hidden
            switch (true) {
              case showing < 0.3:
                margin = (image.height * -0.3);
                break;
              case showing < 0.4:
                margin = (image.height * -0.2);
                break;
              case showing < 0.5:
                margin = (image.height * -0.14);
                break;
              case showing < 0.6:
                margin = (image.height * -0.09);
                break;
              default:
                // Most of the image is showing, do nothing
            }
            $(image).css('margin-top', Math.floor(margin) + 'px');
          }
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
